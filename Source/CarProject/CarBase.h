// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "CarBase.generated.h"

/**
 * 
 */

class UCameraComponent;
class USpringArmComponent;
class UWheeledVehicleMovementComponent;
class USceneComponent;



UCLASS()
class CARPROJECT_API ACarBase : public AWheeledVehicle
{
	GENERATED_BODY()

public :
	ACarBase();

private : 

// Begin Play Event 
virtual void BeginPlay() override;

// Tick Event 
virtual void Tick(float DeltaTime) override;

// Player Input
virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


// Player Camera Look 
UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category = "CameraComp", meta = (AllowPrivateAccess = "true"))
UCameraComponent* CameraFollow;


//camera Spring Arm Comp
UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category = "CameraComp", meta = (AllowPrivateAccess = "true"))
USpringArmComponent* SpringArmFollowYZ;

//Setting Up Scene Comp that holds Projectile Spawning Location 
UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Projectile Location", meta = (AllowPrivateAccess = "true"))
USceneComponent* ProjectileLocation;

// By Gimble Theory to rotate Spring arm Perfectly 
UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category = "CameraComp", meta = (AllowPrivateAccess = "true"))
USceneComponent* GimbleFollowXY;

// Car Movement Function
void MoveForward(float Value);
void TurnRight(float Value);

// Bind Action Events (Hand Break)
void HandBreakPressed();
void HandBreakReleased();

// Scope For On Crosshair And Aiming To AI And Rotation of Turret
UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Scope On/Off", meta = (AllowPrivateAccess = "true"))
bool ScopeValue;

void ScopeOn();
void ScopeOff();




// Mouse Movement Capture to Rotate Spring Arm it helps to move around the car
void LookUp(float Value);
void Turn(float Value);


// Get Existing Wheeled Vehicle Movement Component Refrance.
UWheeledVehicleMovementComponent *WheeledVehicle = GetVehicleMovementComponent();
	
public :


// Cross Visibility Function That callable in blueprint visibility -> On
UFUNCTION(BlueprintImplementableEvent, Category = "Crosshair")
void CrosshairRefOn();

//// Cross Visibility Function That callable in blueprint visibility -> On
UFUNCTION(BlueprintImplementableEvent, Category = "Crosshair")
void CrosshairRefOff();


};
