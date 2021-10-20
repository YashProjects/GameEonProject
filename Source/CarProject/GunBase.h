// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunBase.generated.h"

class UStaticMeshComponent;
class USceneComponent;


UCLASS()
class CARPROJECT_API AGunBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunBase();

	UPROPERTY(EditAnyWhere,BlueprintReadWrite ,Category = "Gun Base")
	UStaticMeshComponent* GunBase;


	UPROPERTY(EditAnyWhere ,BlueprintReadWrite ,Category = "Gun Base")
	UStaticMeshComponent* Gun;

	UPROPERTY(EditAnyWhere ,BlueprintReadWrite ,Category = "Projectile Location")
	USceneComponent* ProjectileLocation;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
