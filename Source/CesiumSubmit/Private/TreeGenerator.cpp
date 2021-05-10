// Fill out your copyright notice in the Description page of Project Settings.

#include <vector>
#include "Math/Vector.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "TreeGenerator.h"

// Sets default values
ATreeGenerator::ATreeGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATreeGenerator::BeginPlay()
{
	Super::BeginPlay();
	

	TreeArray = createTrees(SpawnCount);

	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Created %i number of trees"), TreeArray.size()));

	GetWorld()->GetTimerManager().SetTimer(_loopTimerHandle, this, &ATreeGenerator::onTimerEnd, spawnDelay, true, 2.0f);
}


void ATreeGenerator::SpawnObject(FVector loc, FRotator rot, float vertScale, float horScale)
{
	FActorSpawnParameters SpawnParams;
	AActor* SpawnedRef = GetWorld()->SpawnActor<AActor>(Spawn, loc, rot, SpawnParams);

	if ((vertScale <= 10000.0f && vertScale > 0.f) && (horScale <=5000.f && horScale>0.f)) {
		FVector tempScale = FVector(horScale, vertScale, horScale);
		SpawnedRef->SetActorScale3D(tempScale);
	}

	
	if (currentSpawn < TreeArray.size()) {
		currentSpawn++;
	}
	else {
		GetWorldTimerManager().ClearTimer(_loopTimerHandle);
	}

}

void ATreeGenerator::onTimerEnd()
{
	FVector location = FVector(TreeArray[currentSpawn].positionX, TreeArray[currentSpawn].positionY, TreeArray[currentSpawn].positionZ);
	FRotator rot = FRotator(0, 0, 0);

	//Adjusted tree mesh to be roughly 100 *100 *100 units
//Scaling will be determined by canopy and height / 100
	float vertScale = (TreeArray[currentSpawn].height) / 100;
	float horizScale = (TreeArray[currentSpawn].canopyRadius) / 100;

	SpawnObject(location, rot, vertScale, horizScale);

}

