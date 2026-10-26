// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTService_PlayerLocation.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

UMyBTService_PlayerLocation::UMyBTService_PlayerLocation()
{
	NodeName = TEXT("Store last known player location");
}

void UMyBTService_PlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	// getting player pawn and blackboard component to set the player location in the blackboard
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	UBlackboardComponent* BlackBoard= OwnerComp.GetBlackboardComponent();

	if (PlayerPawn && BlackBoard)
	{
		// getting player location and storing it as a last known player location in the blackboard
		BlackBoard->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
	}
}
