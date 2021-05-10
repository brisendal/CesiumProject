// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/TransformNonVectorized.h"
#include <random> 
#include <vector> 
#include "TreeGenerator.generated.h"

struct Tree {
	// Values are in standard Unreal Engine coordinates (centimeters) 
	float positionX;
	float positionY;
	float positionZ;
	float height;
	float canopyRadius;
};

inline std::vector<Tree> createTrees(size_t numberToCreate) {
	std::default_random_engine generator;
	std::uniform_real_distribution<float> positionDistribution(0.0, 100000.0);
	std::uniform_real_distribution<float> heightDistribution(2.0, 10000.0);
	std::uniform_real_distribution<float> canopyRadiusDistribution(1.0, 5000.0);
	std::vector<Tree> result(numberToCreate);
	for (size_t i = 0; i < numberToCreate; ++i) {
		result[i] = Tree{
		positionDistribution(generator),
		positionDistribution(generator),
		positionDistribution(generator),
		heightDistribution(generator),
		canopyRadiusDistribution(generator)
		};
	}
	return result;
}

UCLASS()
class CESIUMSUBMIT_API ATreeGenerator : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATreeGenerator();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	std::vector<Tree> TreeArray;
	FTransform tempTransform;


	bool begunGen = false;



	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> Spawn;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		int64 SpawnCount = 50;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		float initialSpawnDelay = 2.0f;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		float spawnDelay = 0.5f;

	UFUNCTION()
		void SpawnObject(FVector loc, FRotator rot, float vertScale, float horScale);


	UFUNCTION()
		void onTimerEnd();

private:
	FTimerHandle _loopTimerHandle;
	int currentSpawn = 0;

};