/**
 * Author: Pantelis Andrianakis
 * Date: August 11th 2019
 */

#include "NetworkManager.h"
#include <thread>
#include <Runtime\Sockets\Public\Sockets.h>
#include <Runtime\Sockets\Public\SocketSubsystem.h>
#include <Runtime\Networking\Public\Interfaces\IPv4\IPv4Address.h>
#include <EpicDragonWorld\BitConverter.h>
#include <EpicDragonWorld\SendablePacket.cpp>
#include <EpicDragonWorld\ReceivablePacket.cpp>

static FSocket* socket;
static FIPv4Address ipAddress;
static int32 serverPort = 0;

void UNetworkManager::SetConnectionSettings(const FString ip, const int32 port)
{
	TArray<FString> ipArray;
	ip.ParseIntoArray(ipArray, TEXT("."), false);
	uint8 ipPart1 = FCString::Atoi(*ipArray[0]);
	uint8 ipPart2 = FCString::Atoi(*ipArray[1]);
	uint8 ipPart3 = FCString::Atoi(*ipArray[2]);
	uint8 ipPart4 = FCString::Atoi(*ipArray[3]);
	ipAddress = FIPv4Address(ipPart1, ipPart2, ipPart3, ipPart4);
	serverPort = port;
}

UNetworkManager *const UNetworkManager::GetNetworkManagerInstance()
{
	return this;
}

void UNetworkManager::Connect()
{
	// Must use SetConnectionSettings first.
	if (ipAddress == NULL || serverPort == 0)
	{
		return;
	}

	if (socket != NULL && socket->GetConnectionState() == SCS_Connected)
	{
		// Disconnect if already connected.
		// socket->Close();
		// or...
		return;
	}

	socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);
	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr(ipAddress.Value, serverPort);

	bool connected = socket->Connect(*addr);
	if (connected)
	{
		std::thread listen(&UNetworkManager::ChannelRead, this);
		listen.detach();
	}

	if (!connected)
	{
		Disconnected();
	}
}

void UNetworkManager::ChannelRead()
{
	int32 packetContentLength = 0;
	int32 packetContentSizeLength = 2; // We use 2 bytes for short value.
	uint8_t* bufferLength = new uint8_t[packetContentSizeLength];
	uint8_t* bufferData = new uint8_t[0];
	uint32 length = 0;
	while (socket != NULL && socket->GetConnectionState() == SCS_Connected)
	{
		if (socket->HasPendingData(length))
		{
			socket->Recv(bufferLength, packetContentSizeLength, packetContentSizeLength);
			packetContentLength = BitConverter::ToInt16(bufferLength);
			delete[] bufferData;
			bufferData = new uint8_t[packetContentLength];
			socket->Recv(bufferData, packetContentLength, packetContentLength);

			// TODO: Decrypt bufferData
			
			ReceivablePacket* packet = new ReceivablePacket(bufferData);
			switch (packet->ReadShort())
			{
				case 1:
					FString text = packet->ReadString();
					TestReceive(text);
					break;
			}
			delete packet;
		}
	}
}

void UNetworkManager::ChannelSend(const uint8_t* data, const uint16_t size)
{
	if (socket == NULL || socket->GetConnectionState() != SCS_Connected)
	{
		Disconnected();
		return;
	}

	int32 sent = 0;
	bool successful = socket->Send(data, size, sent);
	if (!successful)
	{
		Disconnected();
	}

	delete[] data;
}

// Sendable information.

void UNetworkManager::TestSend(const FString text)
{
	SendablePacket* packet = new SendablePacket();
	packet->WriteByte(255);
	packet->WriteShort(32767);
	packet->WriteInt(2147483647);
	packet->WriteLong(9223372036854775807);
	packet->WriteFloat(128.1);
	packet->WriteDouble(256.2);
	packet->WriteString(text);
	ChannelSend(packet->GetSendableBytes(), packet->GetSize());
	delete packet;
}

void UNetworkManager::Disconnected_Implementation()
{
}

void UNetworkManager::TestReceive_Implementation(const FString& text)
{
}