/**
 * Author: Pantelis Andrianakis
 * Date: August 14th 2019
 */

#include <EpicDragonWorld\BitConverter.h>

class EPICDRAGONWORLD_API ReceivablePacket
{
private:
	uint8_t* readBuffer;
	uint16_t readBufferPosition;

public:
	ReceivablePacket()
	{
	}

	ReceivablePacket(uint8_t* bytes)
	{
		readBuffer = bytes;
		readBufferPosition = 0;
	}

	~ReceivablePacket()
	{
	}

	FString ReadString()
	{
		// Since we use short value maximum byte size for strings is 32767.
		// Take care that maximum packet size data is 32767 bytes as well.
		// Sending a 32767 byte string would require all the available packet size.

		// Read string size.
		uint8_t* byteArray = new uint8_t[2];
		byteArray[0] = ReadByte();
		byteArray[1] = ReadByte();
		uint16_t size = BitConverter::ToInt16(byteArray);
		delete[] byteArray;

		// Read string bytes.
		uint8_t* rawBytes = new uint8_t[size];
		for (uint16_t i = 0; i < size; i++)
		{
			rawBytes[i] = ReadByte();
		}
		// TODO: Check if need to add 0 byte at the end.

		return FString(UTF8_TO_TCHAR(rawBytes));
		delete[] rawBytes;
	}

	uint8_t ReadByte()
	{
		return readBuffer[readBufferPosition++];
	}

	uint16_t ReadShort()
	{
		uint8_t* byteArray = new uint8_t[2];
		byteArray[0] = ReadByte();
		byteArray[1] = ReadByte();
		return BitConverter::ToInt16(byteArray);
		delete[] byteArray;
	}

	uint32_t ReadInt()
	{
		uint8_t* byteArray = new uint8_t[4];
		byteArray[0] = ReadByte();
		byteArray[1] = ReadByte();
		byteArray[2] = ReadByte();
		byteArray[3] = ReadByte();
		return BitConverter::ToInt32(byteArray);
		delete[] byteArray;
	}

	uint64_t ReadLong()
	{
		uint8_t* byteArray = new uint8_t[8];
		byteArray[0] = ReadByte();
		byteArray[1] = ReadByte();
		byteArray[2] = ReadByte();
		byteArray[3] = ReadByte();
		byteArray[4] = ReadByte();
		byteArray[5] = ReadByte();
		byteArray[6] = ReadByte();
		byteArray[7] = ReadByte();
		return BitConverter::ToInt64(byteArray);
		delete[] byteArray;
	}

	float ReadFloat()
	{
		uint8_t* byteArray = new uint8_t[4];
		byteArray[0] = ReadByte();
		byteArray[1] = ReadByte();
		byteArray[2] = ReadByte();
		byteArray[3] = ReadByte();
		return BitConverter::ToSingle(byteArray);
		delete[] byteArray;
	}

	double ReadDouble()
	{
		uint8_t* byteArray = new uint8_t[8];
		byteArray[0] = ReadByte();
		byteArray[1] = ReadByte();
		byteArray[2] = ReadByte();
		byteArray[3] = ReadByte();
		byteArray[4] = ReadByte();
		byteArray[5] = ReadByte();
		byteArray[6] = ReadByte();
		byteArray[7] = ReadByte();
		return BitConverter::ToDouble(byteArray);
		delete[] byteArray;
	}
};