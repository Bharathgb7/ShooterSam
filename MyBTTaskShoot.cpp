// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTaskShoot.h"
#include "ShooterAI.h"

UMyBTTaskShoot::UMyBTTaskShoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UMyBTTaskShoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	EBTNodeResult::Type Result = EBTNodeResult::Failed;
	
	AShooterAI* OwnerController = Cast<AShooterAI>(OwnerComp.GetAIOwner());
	AShooterSamCharacter* EnemyCharacter = OwnerController->EnemyCharacter;
	AShooterSamCharacter* PlayerCharacter = OwnerController->PlayerCharacter;


	if (OwnerController && EnemyCharacter && PlayerCharacter && PlayerCharacter->IsAlive)
	{
		EnemyCharacter->Shoot();
		Result = EBTNodeResult::Succeeded;
	}
	
	return Result;
	
}
