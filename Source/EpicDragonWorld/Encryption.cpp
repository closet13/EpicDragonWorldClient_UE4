/**
 * Author: Pantelis Andrianakis
 * Date: August 13th 2019
 */

#include "Encryption.h"
#include <Runtime\Core\Public\Misc\AES.h>

static ANSICHAR* KEY = (ANSICHAR*) "1234567890123456";

Encryption::Encryption()
{
}

Encryption::~Encryption()
{
}

uint8_t* Encryption::Encrypt(uint8_t* data)
{
	FAES::EncryptData(data, sizeof(data), KEY);
	return data;
}

uint8_t* Encryption::Decrypt(uint8_t* data)
{
	FAES::DecryptData(data, sizeof(data), KEY);
	return data;
}
