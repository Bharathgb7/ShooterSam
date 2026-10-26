// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterSamCharacter.h"
#include "ShooterAI.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERSAM_API AShooterAI : public AAIController
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	void StartBehaviourTree(AShooterSamCharacter* Player);

	APawn* PlayerPawn;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* EnemyBehaviourTree;

	AShooterSamCharacter* PlayerCharacter;
	AShooterSamCharacter* EnemyCharacter;


};
