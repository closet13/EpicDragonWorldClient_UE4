/**
 * Author: Pantelis Andrianakis
 * Date: August 11th 2019
 */

#pragma once

#include "CoreMinimal.h"

class EPICDRAGONWORLD_API BitConverter
{
public:
	BitConverter();
	~BitConverter();

	static uint8_t ToInt8(uint8_t* buffer);
	static uint16_t ToInt16(uint8_t* buffer);
	static uint32_t ToInt32(uint8_t* buffer);
	static uint64_t ToInt64(uint8_t* buffer);
	static float ToSingle(uint8_t* buffer);
	static double ToDouble(uint8_t* buffer);
	static uint32_t SingleToInt32Bits(float fvalue);
	static uint64_t DoubleToInt64Bits(double dvalue);
};
