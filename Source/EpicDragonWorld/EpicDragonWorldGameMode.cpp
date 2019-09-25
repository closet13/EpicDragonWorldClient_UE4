// Copyright (c) 2018-current Pantelis Andrianakis

#include "EpicDragonWorldGameMode.h"
#include "EpicDragonWorldCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEpicDragonWorldGameMode::AEpicDragonWorldGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
