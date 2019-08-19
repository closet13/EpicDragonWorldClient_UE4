/**
 * Author: Pantelis Andrianakis
 * Date: August 14th 2019
 */

#include "SendablePacket.h"
#include <EpicDragonWorld\BitConverter.h>

uint8_t* writeBuffer;
uint16_t writeBufferSize;

SendablePacket::SendablePacket()
{
	writeBuffer = new uint8_t[0];
	writeBufferSize = 0;
}

SendablePacket::~SendablePacket()
{
}

void SendablePacket::WriteString(FString value)
{
	if (!value.IsEmpty())
	{
		// Since we use short value maximum byte size for strings is 32767.
		// Take care that maximum packet size data is 32767 bytes as well.
		// Sending a 32767 byte string would require all the available packet size.

		// Convert to byte array.
		TArray<TCHAR> byteArray = value.GetCharArray();

		// Write string size.
		size_t size = sizeof(byteArray);
		WriteByte((uint8_t)size);
		WriteByte((uint8_t)(size >> 8));

		// Write string bytes.
		for (uint16_t i = 0; i < size; i++)
		{
			WriteByte(byteArray[i]);
		}
	}
	else
	{
		WriteByte(0);
	}
}

void SendablePacket::WriteByte(uint8_t value)
{
	uint8_t* newArray = new uint8_t[writeBufferSize + 1];
	for (uint16_t i = 0; i < writeBufferSize; i++)
	{
		newArray[i] = writeBuffer[i];
	}
	newArray[writeBufferSize++] = value;
	delete[] writeBuffer;
	writeBuffer = newArray;
}

void SendablePacket::WriteShort(uint16_t value)
{
	WriteByte(value);
	WriteByte(value >> 8);
}

void SendablePacket::WriteInt(uint32_t value)
{
	WriteByte(value);
	WriteByte(value >> 8);
	WriteByte(value >> 16);
	WriteByte(value >> 24);
}

void SendablePacket::WriteLong(uint64_t value)
{
	WriteByte(value);
	WriteByte(value >> 8);
	WriteByte(value >> 16);
	WriteByte(value >> 24);
	WriteByte(value >> 32);
	WriteByte(value >> 40);
	WriteByte(value >> 48);
	WriteByte(value >> 56);
}

void SendablePacket::WriteFloat(float fvalue)
{
	int32_t value = BitConverter::SingleToInt32Bits(fvalue);
	WriteByte(value);
	WriteByte(value >> 8);
	WriteByte(value >> 16);
	WriteByte(value >> 24);
}

void SendablePacket::WriteDouble(double dvalue)
{
	int64_t value = BitConverter::DoubleToInt64Bits(dvalue);
	WriteByte(value);
	WriteByte(value >> 8);
	WriteByte(value >> 16);
	WriteByte(value >> 24);
	WriteByte(value >> 32);
	WriteByte(value >> 40);
	WriteByte(value >> 48);
	WriteByte(value >> 56);
}

uint8_t* SendablePacket::GetSendableBytes()
{
	uint8_t* result = new uint8_t[writeBufferSize + 2];

	// TODO: Encrypt bytes.
	// unsigned char* encryptedBytes = Encryption.Encrypt(writeBuffer);
	uint8_t* encryptedBytes = writeBuffer;
	
	// Create two bytes for length (short - max length 32767).
	uint16_t resultPos = 0;
	result[resultPos++] = (uint8_t)writeBufferSize;
	result[resultPos++] = (uint8_t)(writeBufferSize >> 8);

	// Join bytes.
	for (uint16_t i = 0; i < writeBufferSize; i++)
	{
		result[resultPos++] = encryptedBytes[i];
	}

	// Cleanup.
	delete[] encryptedBytes;

	// Return the data.
	return result;
}

uint16_t SendablePacket::GetSize()
{
	return writeBufferSize + 2;
}