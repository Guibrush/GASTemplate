// Copyright Epic Games, Inc. All Rights Reserved.

#include "GASTemplateGameMode.h"
#include "GASTemplateCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGASTemplateGameMode::AGASTemplateGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
