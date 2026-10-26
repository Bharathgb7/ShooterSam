// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearBlackBoardValue.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_ClearBlackBoardValue::UBTTask_ClearBlackBoardValue()
{
	NodeName = TEXT("Clear Last Known Player Location Value");
}

EBTNodeResult::Type UBTTask_ClearBlackBoardValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	//called when the task is executed in the behaviour tree.
	Super::ExecuteTask(OwnerComp, NodeMemory);

	// getting the blackboard to access the values and clear it 
	UBlackboardComponent* BlackBoard = OwnerComp.GetBlackboardComponent();
	if (BlackBoard)
	{
		BlackBoard->ClearValue(GetSelectedBlackboardKey());
	}

	return EBTNodeResult::Succeeded;
}
