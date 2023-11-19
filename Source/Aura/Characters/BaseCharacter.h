// Copyright Coherence Studios

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Abstract)
class AURA_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ABaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	TObjectPtr<class UAttributeSet> GetAttributeSet() const { return AttributeSet; };
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UAttributeSet> AttributeSet;
};
