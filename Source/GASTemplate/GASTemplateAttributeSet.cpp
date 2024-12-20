// Fill out your copyright notice in the Description page of Project Settings.


#include "GASTemplateAttributeSet.h"
#include "GASTemplateCharacter.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

void UGASTemplateAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
	// Get the Target actor, which should be our owner
	AActor* TargetActor = nullptr;
	// AController* TargetController = nullptr;
	AGASTemplateCharacter* TargetCharacter = nullptr;
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		// TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		TargetCharacter = Cast<AGASTemplateCharacter>(TargetActor);
	}

	if (!TargetCharacter)
		return;
	
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		if (Data.EvaluatedData.Attribute.GetNumericValue(this) <= 0.f && TargetCharacter->GetIsAlive())
		{
			TargetCharacter->Die();
		}

		SetHealth(FMath::Clamp(Data.EvaluatedData.Attribute.GetNumericValue(this), 0.0f, GetMaxHealth()));
	}

	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(Data.EvaluatedData.Attribute.GetNumericValue(this), 0.0f, GetMaxMana()));
	}
}

void UGASTemplateAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UGASTemplateAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASTemplateAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASTemplateAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASTemplateAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UGASTemplateAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASTemplateAttributeSet, Health, OldHealth);
}

void UGASTemplateAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASTemplateAttributeSet, MaxHealth, OldMaxHealth);
}

void UGASTemplateAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASTemplateAttributeSet, Mana, OldMana);
}

void UGASTemplateAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASTemplateAttributeSet, MaxMana, OldMaxMana);
}
