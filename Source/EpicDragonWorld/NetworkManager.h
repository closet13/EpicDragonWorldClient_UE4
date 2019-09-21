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

public:
	UFUNCTION(BlueprintCallable, Category = "MMORPG Networking")
	UNetworkManager *const GetNetworkManagerInstance();

	UFUNCTION(BlueprintCallable, Category = "MMORPG Networking")
	void SetConnectionSettings(const FString ip, const int32 port);

	UFUNCTION(BlueprintCallable, Category = "MMORPG Networking")
	void Connect();

	void ChannelRead();

	void ChannelSend(const uint8_t* data, const uint16_t size);

	// Sendable information.

	UFUNCTION(BlueprintCallable, Category = "MMORPG Networking|Sendable Information|Test Send")
	void TestSend(const FString text);

	// Receivable events.

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MMORPG Networking|Receivable Events|Disconnected")
	void Disconnected();
	virtual void Disconnected_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "MMORPG Networking|Receivable Events|Test Receive")
	void TestReceive(const FString& text);
	virtual void TestReceive_Implementation(const FString& text);
};
