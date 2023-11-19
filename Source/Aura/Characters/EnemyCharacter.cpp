// Copyright Coherence Studios


#include "EnemyCharacter.h"
#include <Aura/Aura.h>
#include "Aura/AbilitySystem/AuraAbilitySystemComponent.h"
#include "Aura/AbilitySystem/AuraAttributeSet.h"

AEnemyCharacter::AEnemyCharacter() {
  GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

  AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
  AbilitySystemComponent->SetIsReplicated(true);
  AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
  
  AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AEnemyCharacter::HighlightActor() {
  GetMesh()->SetRenderCustomDepth(true);
  GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
  Weapon->SetRenderCustomDepth(true);
  Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AEnemyCharacter::UnHighlightActor() {
  GetMesh()->SetRenderCustomDepth(false);
  Weapon->SetRenderCustomDepth(false);
}

void AEnemyCharacter::BeginPlay() {
  Super::BeginPlay();
  AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
