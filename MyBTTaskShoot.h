// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "MyBTTaskShoot.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERSAM_API UMyBTTaskShoot : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UMyBTTaskShoot();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp,
		uint8* NodeMemory
	)override;
	
};
