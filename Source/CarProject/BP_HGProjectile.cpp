// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_HGProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABP_HGProjectile::ABP_HGProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->MaxSpeed = 50000.f;
	ProjectileMovement->InitialSpeed = 50000.f;
	ProjectileMovement->ProjectileGravityScale = 0.f;


	


}

// Called when the game starts or when spawned
void ABP_HGProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_HGProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

