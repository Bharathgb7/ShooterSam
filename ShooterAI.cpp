// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAI.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AShooterAI::BeginPlay()
{
	Super::BeginPlay();

	
}

void AShooterAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

/*  	// we need player pawn to focus on us since we use ai as player character
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (PlayerPawn)
	{
		// lose sight when player hides behind wall
		if (LineOfSightTo(PlayerPawn))
		{
			SetFocus(PlayerPawn);
			// move the ai towards player
			MoveToActor(PlayerPawn, 200.0f);
		}
		else
		{ 
			ClearFocus(EAIFocusPriority::Gameplay);
			StopMovement();
		}
	}  ai logic moved to behaviour trees */

}

void AShooterAI::StartBehaviourTree(AShooterSamCharacter* Player)
{
	if (EnemyBehaviourTree)
	{
		if (Player)
		{
			// getting enemy character using a pawn ptr then converting into a player type character
			EnemyCharacter = Cast<AShooterSamCharacter>(GetPawn());
			
			//storing player character to AshooterSamcharacter type to access its properties
			PlayerCharacter = Player;
		}
		RunBehaviorTree(EnemyBehaviourTree);

		// setting the blackboard values for the player and enemy characters
		UBlackboardComponent* MyBlackBoard = GetBlackboardComponent();
		if (MyBlackBoard && PlayerCharacter)
		{
			// passing enemy's starting location to BB inorder to return back to its starting point after it reaches player's loc
			MyBlackBoard->SetValueAsVector("StartLocation", EnemyCharacter->GetActorLocation());
		}
	}
}
