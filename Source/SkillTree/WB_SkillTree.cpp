#include "WB_SkillTree.h"
#include "Skill.h"

#include "Engine/Engine.h"

void UWB_SkillTree::NativeConstruct()
{
	Super::NativeConstruct();

	InitializeSkillTree();

	TArray<USkill*> All;

	All.Append(PowerSkills);
	All.Append(MagicSkills);
	All.Append(StealthSkills);

	for (USkill* Skill : All)
	{
		if (Skill)
		{
			Skill->SkillTree = this;
		}
	}

	FString Msg = FString::Printf(TEXT("Tienes %d puntos de experiencia"), ExperiencePoints);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Msg);

	UpdateAllSkills();
}

void UWB_SkillTree::InitializeSkillTree()
{
	PowerSkills = {
		Power_1, Power_2, Power_3, Power_4, Power_5, Power_6,
		Power_7, Power_8, Power_9, Power_10, Power_11, Power_12
	};

	MagicSkills = {
		Magic_1, Magic_2, Magic_3, Magic_4, Magic_5, Magic_6,
		Magic_7, Magic_8, Magic_9, Magic_10, Magic_11, Magic_12
	};

	StealthSkills = {
		Stealth_1, Stealth_2, Stealth_3, Stealth_4, Stealth_5, Stealth_6,
		Stealth_7, Stealth_8, Stealth_9, Stealth_10, Stealth_11, Stealth_12
	};
}

void UWB_SkillTree::ConfigureBranch(TArray<USkill*>& Branch)
{
}

void UWB_SkillTree::UpdateAllSkills()
{
	TArray<USkill*> All;

	All.Append(PowerSkills);
	All.Append(MagicSkills);
	All.Append(StealthSkills);

	for (USkill* Skill : All)
	{
		if (Skill)
		{
			Skill->RefreshState();
		}
	}
}