// Copyright Epic Games, Inc. All Rights Reserved.

#include "CesiumSubmitGameMode.h"
#include "CesiumSubmitHUD.h"
#include "CesiumSubmitCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACesiumSubmitGameMode::ACesiumSubmitGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ACesiumSubmitHUD::StaticClass();
}
