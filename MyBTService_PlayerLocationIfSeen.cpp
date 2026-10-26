// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTService_PlayerLocationIfSeen.h"
#include "ShooterAI.h"
#include "BehaviorTree/BlackboardComponent.h"

UMyBTService_PlayerLocationIfSeen::UMyBTService_PlayerLocationIfSeen()
{
	NodeName = TEXT("Update Player Location If Seen");
}

void UMyBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	//UE_LOG(LogTemp, Display, TEXT("Service is Runnning = %f"),DeltaSeconds);

	// Get the AI controller that owns this behavior tree
	AShooterAI* OwnerController = Cast<AShooterAI>(OwnerComp.GetAIOwner());

	AShooterSamCharacter* Player = OwnerController->PlayerCharacter;

	// getting the blackboard component to set the player location if seen
	UBlackboardComponent* BlackBoard = OwnerController-> GetBlackboardComponent();

	if (OwnerController && Player && BlackBoard)
	{
		// if player in enemy's line of sight then follow or else stop following
		if(OwnerController->LineOfSightTo(Player))
		{
			// to get player location if the enemy sees the player 
			//GetSelectedBlackboardKey used to get the name of the blackboard key that is selected in the editor for this service node
			BlackBoard->SetValueAsVector(GetSelectedBlackboardKey(), Player->GetActorLocation());

			OwnerController->SetFocus(Player);
		}
		else
		{
			// clears the player location from the blackboard if the enemy loses sight of the player
			// this will move to next condition in the behaviour tree 
			BlackBoard->ClearValue(GetSelectedBlackboardKey());
			OwnerController->ClearFocus(EAIFocusPriority::Gameplay);
		}
	}

}
