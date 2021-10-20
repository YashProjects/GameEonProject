// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BP_HGProjectile.generated.h"


class UStaticMeshComponent;

UCLASS()
class CARPROJECT_API ABP_HGProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABP_HGProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Projectile Mesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Projectile Mov", meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent*ProjectileMovement;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
