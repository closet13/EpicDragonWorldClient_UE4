/**
 * Author: Pantelis Andrianakis
 * Date: August 14th 2019
 */

#include "CoreMinimal.h"

class EPICDRAGONWORLD_API ReceivablePacket
{
public:
	ReceivablePacket();
	ReceivablePacket(uint8_t* bytes);
	~ReceivablePacket();

	static FString ReadString();
	static uint8_t ReadByte();
	static uint16_t ReadShort();
	static uint32_t ReadInt();
	static uint64_t ReadLong();
	static float ReadFloat();
	static double ReadDouble();
};
