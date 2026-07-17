#include "Skill.h"
#include "WB_SkillTree.h"

#include "Components/Button.h"
#include "Engine/Engine.h"

void USkill::NativeConstruct()
{
	Super::NativeConstruct();

	if (Button)
	{
		Button->OnClicked.AddDynamic(this, &USkill::OnSkillClicked);
	}
}

void USkill::OnSkillClicked()
{
	if (bUnlocked)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, TEXT("Ya estaba desbloqueada"));
		return;
	}

	if (!SkillTree)
	{
		return;
	}

	if (SkillTree->ExperiencePoints <= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("No quedan puntos"));
		return;
	}

	if (CanUnlock())
	{
		Unlock();

		SkillTree->ExperiencePoints--;

		FString Msg = FString::Printf(TEXT("Puntos restantes: %d"), SkillTree->ExperiencePoints);
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, Msg);

		SkillTree->UpdateAllSkills();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("No puedes desbloquearla aún"));
	}
}

bool USkill::CanUnlock() const
{
	if (!PreviousSkill)
	{
		return true;
	}

	return PreviousSkill->bUnlocked;
}

void USkill::Unlock()
{
	bUnlocked = true;
}

void USkill::RefreshState()
{
	if (bUnlocked)
	{
		return;
	}

	if (CanUnlock())
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, TEXT("Skill disponible"));
	}
}