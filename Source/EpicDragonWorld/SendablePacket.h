/**
 * Author: Pantelis Andrianakis
 * Date: August 14th 2019
 */

#include "CoreMinimal.h"

class EPICDRAGONWORLD_API SendablePacket
{
public:
	SendablePacket();
	~SendablePacket();

	static void WriteString(FString value);
	static void WriteByte(uint8_t value);
	static void WriteShort(uint16_t value);
	static void WriteInt(uint32_t value);
	static void WriteLong(uint64_t value);
	static void WriteFloat(float fvalue);
	static void WriteDouble(double dvalue);
	static uint8_t* GetSendableBytes();
	static uint16_t GetSize();
};
