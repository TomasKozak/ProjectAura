// Copyright Coherence Studios


#include "BasePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include <Aura/Interaction/EnemyInterface.h>

ABasePlayerController::ABasePlayerController() {
  bReplicates = true;
}

void ABasePlayerController::PlayerTick(float DeltaTime) {
  Super::PlayerTick(DeltaTime);

  CursorTrace();
}

void ABasePlayerController::CursorTrace() {
  FHitResult CursorHit;
  GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
  if (!CursorHit.bBlockingHit) return;
  
  LastActor = ThisActor;
  ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

  if (LastActor == nullptr) {
    if (ThisActor != nullptr) {
      ThisActor->HighlightActor();
    } 
  } else {
    if (ThisActor == nullptr) {
      LastActor->UnHighlightActor();
    } else {
      if (LastActor != ThisActor) {
        LastActor->UnHighlightActor();
        ThisActor->HighlightActor();
      }
    }
  }
}


void ABasePlayerController::BeginPlay() {
  Super::BeginPlay();

  check(AuraContext);

  UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
 if (Subsystem)
 {
  Subsystem->AddMappingContext(AuraContext, 0);
 }

  bShowMouseCursor = true;
  DefaultMouseCursor = EMouseCursor::Default;

  FInputModeGameAndUI InputModeData;
  InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
  InputModeData.SetHideCursorDuringCapture(false);
  SetInputMode(InputModeData);
}

void ABasePlayerController::SetupInputComponent() {
  Super::SetupInputComponent();

  UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

  EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABasePlayerController::Move);

}

void ABasePlayerController::Move(const FInputActionValue& InputActionValue) {
  const FVector2D InputActionVector = InputActionValue.Get<FVector2D>();
  const FRotator Rotation = GetControlRotation();
  const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

  const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
  const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

  if (APawn* ControlledPawn = GetPawn<APawn>()) {
    ControlledPawn->AddMovementInput(ForwardDirection, InputActionVector.Y);
    ControlledPawn->AddMovementInput(RightDirection, InputActionVector.X);
  }
}

