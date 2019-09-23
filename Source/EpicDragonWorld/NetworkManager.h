/**
 * Author: Pantelis Andrianakis
 * Date: August 11th 2019
 */

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NetworkManager.generated.h"

UCLASS()
class EPICDRAGONWORLD_API UNetworkManager : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "MMORPG Networking")

	static void SetConnectionSettings(const FString ip, const int32 port);

	UFUNCTION(BlueprintCallable, Category = "MMORPG Networking")
	static void Connect();

	static void ChannelRead();

	static void ChannelSend(const uint8_t* data, const uint16_t size);

	// Sendable information.

	UFUNCTION(BlueprintCallable, Category = "MMORPG Networking|Sendable Information|Test Send")
	static void TestSend(const FString text);

	// Receivable events.

	UFUNCTION(BlueprintCallable, Category = "MMORPG Networking|Receivable Events|Disconnected")
	static void Disconnected();

	UFUNCTION(BlueprintCallable, Category = "MMORPG Networking|Receivable Events|Test Receive")
	static void TestReceive(const FString& text);
};
