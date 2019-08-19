/**
 * Author: Pantelis Andrianakis
 * Date: August 13th 2019
 */

#pragma once

#include "CoreMinimal.h"

class EPICDRAGONWORLD_API Encryption
{
public:
	Encryption();
	~Encryption();

	uint8_t* Encrypt(uint8_t* data);
	uint8_t* Decrypt(uint8_t* data);
};
