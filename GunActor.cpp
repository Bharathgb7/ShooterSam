// Fill out your copyright notice in the Description page of Project Settings.


#include "GunActor.h"
#include "Kismet/GameplayStatics.h"

//macros
#define LOG_WARNING(x) UE_LOG(LogTemp , Warning, TEXT(x))

// Sets default values
AGunActor::AGunActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	SetRootComponent(SceneRoot);
	
	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun Mesh"));
	GunMesh->SetupAttachment(SceneRoot);

	MuzzleFlash = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Muzzle Flash"));
	MuzzleFlash->SetupAttachment(GunMesh);
}

// Called when the game starts or when spawned
void AGunActor::BeginPlay()
{
	Super::BeginPlay();
	
	// deactivate since it shows the muzzle effect even before we fire
	MuzzleFlash->Deactivate();

	// UE_LOG(LogTemp , Warning, TEXT("this is a warning"))
	// macros for the log refer the top line of this file
	LOG_WARNING("This is a warning");
}

// Called every frame
void AGunActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGunActor::PullTrigger()
{
	// activate when we start firing the gun	
	MuzzleFlash->Activate(true);

	if (OwnerController)
	{
		FVector ViewPointLocation;
		FRotator ViewPointRotation;

		// if a function arguments shown as & symbol that is known as out parameters
		OwnerController->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);

		//DrawDebugCamera(GetWorld(), ViewPointLocation, ViewPointRotation, 90.0f,2.0f,FColor::Red,true);

		//line trace for bullets
		FHitResult HitResult;
		FVector EndLocation = ViewPointLocation + ViewPointRotation.Vector() * MaxRange;

		// used to ignore the line trace for actors gun and player since it counts the them also
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);
		Params.AddIgnoredActor(GetOwner());

		bool IsHit = GetWorld()->LineTraceSingleByChannel(HitResult,
			ViewPointLocation,
			EndLocation,
			ECC_GameTraceChannel1,
			Params);

		if (IsHit)
		{
			//DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 5.0f, 6, FColor::Blue, true);
			if (ImpactEffect)
			{
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(),
					ImpactEffect,
					HitResult.ImpactPoint,
					HitResult.ImpactPoint.Rotation() 
				);
			}

			// applying damage after hit by bullet
			AActor* HitActor = HitResult.GetActor();
			if (HitActor)
			{
				UGameplayStatics::ApplyDamage(HitActor,
					BulletDamage,
					OwnerController, 
					this, 
					UDamageType::StaticClass()
				);
			}
			
		}

	}
}

