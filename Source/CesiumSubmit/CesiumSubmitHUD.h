// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CesiumSubmitHUD.generated.h"

UCLASS()
class ACesiumSubmitHUD : public AHUD
{
	GENERATED_BODY()

public:
	ACesiumSubmitHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

