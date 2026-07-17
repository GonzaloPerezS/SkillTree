#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WB_SkillTree.generated.h"

class UCanvasPanel;
class USkill;

UCLASS()
class SKILLTREE_API UWB_SkillTree : public UUserWidget
{
	GENERATED_BODY()

protected:

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* CanvasPanel;

	UPROPERTY(meta = (BindWidget)) USkill* Power_1;
	UPROPERTY(meta = (BindWidget)) USkill* Power_2;
	UPROPERTY(meta = (BindWidget)) USkill* Power_3;
	UPROPERTY(meta = (BindWidget)) USkill* Power_4;
	UPROPERTY(meta = (BindWidget)) USkill* Power_5;
	UPROPERTY(meta = (BindWidget)) USkill* Power_6;
	UPROPERTY(meta = (BindWidget)) USkill* Power_7;
	UPROPERTY(meta = (BindWidget)) USkill* Power_8;
	UPROPERTY(meta = (BindWidget)) USkill* Power_9;
	UPROPERTY(meta = (BindWidget)) USkill* Power_10;
	UPROPERTY(meta = (BindWidget)) USkill* Power_11;
	UPROPERTY(meta = (BindWidget)) USkill* Power_12;

	UPROPERTY(meta = (BindWidget)) USkill* Magic_1;
	UPROPERTY(meta = (BindWidget)) USkill* Magic_2;
	UPROPERTY(meta = (BindWidget)) USkill* Magic_3;
	UPROPERTY(meta = (BindWidget)) USkill* Magic_4;
	UPROPERTY(meta = (BindWidget)) USkill* Magic_5;
	UPROPERTY(meta = (BindWidget)) USkill* Magic_6;
	UPROPERTY(meta = (BindWidget)) USkill* Magic_7;
	UPROPERTY(meta = (BindWidget)) USkill* Magic_8;
	UPROPERTY(meta = (BindWidget)) USkill* Magic_9;
	UPROPERTY(meta = (BindWidget)) USkill* Magic_10;
	UPROPERTY(meta = (BindWidget)) USkill* Magic_11;
	UPROPERTY(meta = (BindWidget)) USkill* Magic_12;

	UPROPERTY(meta = (BindWidget)) USkill* Stealth_1;
	UPROPERTY(meta = (BindWidget)) USkill* Stealth_2;
	UPROPERTY(meta = (BindWidget)) USkill* Stealth_3;
	UPROPERTY(meta = (BindWidget)) USkill* Stealth_4;
	UPROPERTY(meta = (BindWidget)) USkill* Stealth_5;
	UPROPERTY(meta = (BindWidget)) USkill* Stealth_6;
	UPROPERTY(meta = (BindWidget)) USkill* Stealth_7;
	UPROPERTY(meta = (BindWidget)) USkill* Stealth_8;
	UPROPERTY(meta = (BindWidget)) USkill* Stealth_9;
	UPROPERTY(meta = (BindWidget)) USkill* Stealth_10;
	UPROPERTY(meta = (BindWidget)) USkill* Stealth_11;
	UPROPERTY(meta = (BindWidget)) USkill* Stealth_12;

	TArray<USkill*> PowerSkills;
	TArray<USkill*> MagicSkills;
	TArray<USkill*> StealthSkills;

	void InitializeSkillTree();
	void ConfigureBranch(TArray<USkill*>& Branch);

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill Tree")
	int32 ExperiencePoints = 25;

	void UpdateAllSkills();
};