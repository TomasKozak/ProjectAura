// Copyright Coherence Studios

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "AuraPlayerState.generated.h"

UCLASS()
class AURA_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraPlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	TObjectPtr<class UAttributeSet> GetAttributeSet() const { return AttributeSet; };

protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UAttributeSet> AttributeSet;
};
