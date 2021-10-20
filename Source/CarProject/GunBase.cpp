// Fill out your copyright notice in the Description page of Project Settings.


#include "GunBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
AGunBase::AGunBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Gun Base If Gun Have 
	GunBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gun Base"));
	
	// Original Gun Mesh
	Gun = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gun"));
	//Gun->SetupAttachment(GunBase);
	// FTransform SocketTransform = GunBase->GetSocketTransform("Gun");
	// Gun->AttachTo(GunBase, SocketTransform, EAttachLocation::SnapToTarget, false);

	ProjectileLocation = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Location"));
	ProjectileLocation->SetupAttachment(Gun);
	


}

// Called when the game starts or when spawned
void AGunBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGunBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

