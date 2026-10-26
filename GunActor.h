// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "GunActor.generated.h"


UCLASS()
class SHOOTERSAM_API AGunActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;
	
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* GunMesh;

	AController* OwnerController;
	
	UPROPERTY(EditAnywhere)
	float MaxRange = 10000.0f;

	UPROPERTY(EditAnywhere)
	UNiagaraComponent* MuzzleFlash;

	UPROPERTY(EditAnywhere)
	UNiagaraSystem* ImpactEffect;

	UPROPERTY(EditAnywhere)
	float BulletDamage = 10.0f;

	void PullTrigger();
};
