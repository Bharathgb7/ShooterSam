// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooterSamGameMode.h"
#include "Kismet/GameplayStatics.h"

AShooterSamGameMode::AShooterSamGameMode()
{
	// stub
}

void AShooterSamGameMode::BeginPlay()
{
	Super::BeginPlay();

	AShooterSamCharacter* Player = 
		Cast<AShooterSamCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	// getting all of the ai actors in the world and storing them in an array 
	// loop over the array and call the start behaviour tree function for each ai actor

	// why AActor type array? because the function GetAllActorsOfClass returns an array of AActor type
	TArray<AActor*> EnemyAIActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AShooterAI::StaticClass(), EnemyAIActors);

	//var used to indexing through the array of ai actors int32 LoopIndex = 0; while loop method
	/*while (LoopIndex < EnemyAIActors.Num())
	{
		AActor* EnemyActor = EnemyAIActors[LoopIndex];
		LoopIndex++;
	}*/

	for (int32 LoopIndex = 0; LoopIndex < EnemyAIActors.Num(); LoopIndex++)
	{
		AActor* EnemyActor = EnemyAIActors[LoopIndex];
		AShooterAI* EnemyAI = Cast<AShooterAI>(EnemyActor);
		if (EnemyAI)
		{
			EnemyAI->StartBehaviourTree(Player);
			UE_LOG(LogTemp, Display, TEXT("Enemy AI Character Name = %s"), *EnemyAI->GetActorNameOrLabel());
		}
	}
}
