// Copyright Epic Games, Inc. All Rights Reserved.

#include "GASTemplateGameMode.h"
#include "GASTemplateCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGASTemplateGameMode::AGASTemplateGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/GASTemplate/Characters/BP_PlayerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
