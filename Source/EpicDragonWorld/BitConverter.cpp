/**
 * Author: Pantelis Andrianakis
 * Date: August 11th 2019
 */

#include "BitConverter.h"

BitConverter::BitConverter()
{
}

BitConverter::~BitConverter()
{
}

uint8_t BitConverter::ToInt8(uint8_t* buffer)
{
	return uint8_t(buffer[0]);
}

uint16_t BitConverter::ToInt16(uint8_t* buffer)
{
	return uint16_t(
		buffer[1] << 8 |
		buffer[0]);
}

uint32_t BitConverter::ToInt32(uint8_t* buffer)
{
	return uint32_t(
		buffer[3] << 24 |
		buffer[2] << 16 |
		buffer[1] << 8 |
		buffer[0]);
}

uint64_t BitConverter::ToInt64(uint8_t* buffer)
{
	return uint64_t(
		(uint64_t)(buffer[7]) << 56 |
		(uint64_t)(buffer[6]) << 48 |
		(uint64_t)(buffer[5]) << 40 |
		(uint64_t)(buffer[4]) << 32 |
		buffer[3] << 24 |
		buffer[2] << 16 |
		buffer[1] << 8 |
		buffer[0]);
}

float BitConverter::ToSingle(uint8_t* buffer)
{
	uint32_t f = ToInt32(buffer);
	return *reinterpret_cast<float*>(&f);
}

double BitConverter::ToDouble(uint8_t* buffer)
{
	uint64_t d = ToInt64(buffer);
	return *reinterpret_cast<double*>(&d);
}

uint32_t BitConverter::SingleToInt32Bits(float fvalue)
{
	return *(uint32_t*)(&fvalue);
}

uint64_t BitConverter::DoubleToInt64Bits(double dvalue)
{
	return *(uint64_t*)(&dvalue);
}
