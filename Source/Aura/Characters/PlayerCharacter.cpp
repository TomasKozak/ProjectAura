// Copyright Coherence Studios


#include "PlayerCharacter.h"
#include "Aura/Player/AuraPlayerState.h"
#include "Aura/Player/BasePlayerController.h"
#include "Aura/UI/AuraHUD.h"
#include "GameFramework/CharacterMovementComponent.h"

APlayerCharacter::APlayerCharacter() {

  GetCharacterMovement()->bOrientRotationToMovement = true;
  GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
  GetCharacterMovement()->bConstrainToPlane = true;
  GetCharacterMovement()->bSnapToPlaneAtStart = true;
  
  bUseControllerRotationPitch = false;
  bUseControllerRotationRoll = false;
  bUseControllerRotationYaw = false;
}

void APlayerCharacter::PossessedBy(AController* NewController) {
  Super::PossessedBy(NewController);
  InitAbilityActorInfo();
}

void APlayerCharacter::OnRep_PlayerState() {
  Super::OnRep_PlayerState();
  InitAbilityActorInfo();
}

void APlayerCharacter::InitAbilityActorInfo() {
  AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
  check(AuraPlayerState);
  AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
  AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
  AttributeSet = AuraPlayerState->GetAttributeSet();

  if (ABasePlayerController* BasePlayerController = Cast<ABasePlayerController>(GetController()))
  {
    if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(BasePlayerController->GetHUD()))
    {
      AuraHUD->InitOverlay(BasePlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
    }
  }
}


