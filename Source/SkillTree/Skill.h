#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Skill.generated.h"

class UButton;
class UWB_SkillTree;

UCLASS()
class SKILLTREE_API USkill : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	USkill* PreviousSkill = nullptr;

	UPROPERTY(BlueprintReadOnly)
	bool bUnlocked = false;

	UPROPERTY()
	UWB_SkillTree* SkillTree = nullptr;

	void RefreshState();

protected:

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* Button;

	UFUNCTION()
	void OnSkillClicked();

	bool CanUnlock() const;
	void Unlock();
};