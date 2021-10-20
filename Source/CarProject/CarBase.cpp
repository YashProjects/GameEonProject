// Fill out your copyright notice in the Description page of Project Settings.


#include "CarBase.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Engine/Engine.h"
#include "WheeledVehicle.h"
#include "WheeledVehicleMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneComponent.h"
#include "Math/Quat.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"
#include "CarHUD.h"





//Constructor All Defaults Values
ACarBase::ACarBase()
{
    PrimaryActorTick.bCanEverTick = true;

    GimbleFollowXY = CreateDefaultSubobject<USceneComponent>(TEXT("Gimble"));
    GimbleFollowXY->SetupAttachment(this->GetMesh());

    // Spring Arm TO hold Camera And Attached To Player Character Mesh 
    SpringArmFollowYZ = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArmFollowYZ->TargetArmLength = 750;
    SpringArmFollowYZ->SetupAttachment(GimbleFollowXY);

    // Settingup an Not Getting any Pawn Rotation to camera/Spring Arm
    SpringArmFollowYZ->bInheritPitch = false;
    SpringArmFollowYZ->bInheritRoll = false;
    SpringArmFollowYZ->bInheritYaw = false;


    // Camera that player can see world and attached to spring arm
    CameraFollow = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Comp"));
    CameraFollow->SetupAttachment(SpringArmFollowYZ);

    //Scene Component that holds Projectile Location
    ProjectileLocation = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Location"));
    // ProjectileLocation->SetupAttachment(Gimble);


}

// Begin Play Strat At Begging On Play
void ACarBase::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("Worked..!"));



}

// Tick Function Count Every Frame 
void ACarBase::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);


}

// Player All Inputs
void ACarBase::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) 
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Player Input For Moving Forward And Right Vector
    PlayerInputComponent->BindAxis("Forward", this, &ACarBase::MoveForward);
    PlayerInputComponent->BindAxis("TurnRight", this, &ACarBase::TurnRight);

    //Player Input For Controlling View Mode Of Mouse 
    PlayerInputComponent->BindAxis("LookUp", this, &ACarBase::LookUp);
    PlayerInputComponent->BindAxis("Turn", this, &ACarBase::Turn);



    //Action Event for Argent Break
    PlayerInputComponent->BindAction("HandBreak", IE_Pressed, this, &ACarBase::HandBreakPressed);
    PlayerInputComponent->BindAction("HandBreak", IE_Released, this, &ACarBase::HandBreakReleased);

    // Crosshair / Player Ready to fire mode - mouse right click
    PlayerInputComponent->BindAction("Scope", IE_Pressed, this, &ACarBase::ScopeOn);
    PlayerInputComponent->BindAction("Scope", IE_Released, this, &ACarBase::ScopeOff);



}

// Car Forward Movement
void ACarBase::MoveForward(float Value)
{
    WheeledVehicle->SetThrottleInput(Value);
}

// Car Turning Movement
void ACarBase::TurnRight(float Value)
{
    WheeledVehicle->SetSteeringInput(Value);
    
}

// Setting Break For Car to true 
void ACarBase::HandBreakPressed()
{
    WheeledVehicle->SetHandbrakeInput(true);
}

// Released HandBreak
void ACarBase::HandBreakReleased()
{
    WheeledVehicle->SetHandbrakeInput(false);
}

void ACarBase::ScopeOn()
{
    ScopeValue = true;
    if(GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1,
         1.0f,
          FColor::Green,
           TEXT("Scope Mode is On..!"),
            true);
    }

    auto PlayerController = UGameplayStatics::GetPlayerController(this, 0);
    ACarHUD * hud = Cast<ACarHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());

    // Getting CrosshairUI Ref here and Make Visibility Crontrol

    CrosshairRefOn();


}

void ACarBase::ScopeOff()
{
    ScopeValue = false;

        if(GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1,
         1.0f,
          FColor::Green,
           TEXT("Scope Mode is Off..!"),
            true);
    }

    CrosshairRefOff();

    
    auto PlayerController = UGameplayStatics::GetPlayerController(this, 0);
    ACarHUD * hud = Cast<ACarHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());

    // Getting CrosshairUI Ref here and Make Visibility Crontrol


}

// // Mouse Movement on Yaw Direction 
void ACarBase::LookUp(float Value)
{
    //Setting up Properties for Gimble Movement
    float DeltaTime = GetWorld()->GetDeltaSeconds();
    float GimbleYaw = (Value * DeltaTime * 100.0f);

    //Applying Rotation To Gimble 
    GimbleFollowXY->AddRelativeRotation(FRotator(0.f, GimbleYaw, 0.f).Quaternion());

}

// Mosue Movement on Pitch Direction 
void ACarBase::Turn(float Value)
{
    // Used name YZ cause UE already have springarmfollow Naming Component
    SpringArmFollowYZ->AddRelativeRotation(FRotator(Value, 0.f, 0.f).Quaternion());

}

