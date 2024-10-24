// Fill out your copyright notice in the Description page of Project Settings.


#include "GASTemplateAttributeSet.h"
#include "Net/UnrealNetwork.h"

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
