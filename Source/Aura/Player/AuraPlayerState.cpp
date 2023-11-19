// Copyright Coherence Studios


#include "AuraPlayerState.h"

#include "Aura/AbilitySystem/AuraAbilitySystemComponent.h"
#include "Aura/AbilitySystem/AuraAttributeSet.h"


AAuraPlayerState::AAuraPlayerState() {
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
  
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const {
	return AbilitySystemComponent;
}
