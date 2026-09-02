#include "pch.h"
#include "SkillSlot.h"
#include "Text.h"
#include "Skill.h"

SkillSlot::SkillSlot()
{
}

SkillSlot::~SkillSlot()
{
}

void SkillSlot::Init(Skill* skill)
{
	this->skill = skill;
	name->SetText(skill->GetNameText());
	description->SetText(skill->GetDescriptionText());

	if (skill->GetLevel() == 0)
		level->SetText(L"NEW!");
	else if (skill->GetLevel() == -1)
		level->SetText(L"Item");
	else if (skill->GetLevel() == 9)
		level->SetText(std::to_wstring(skill->GetLevel()) + L" -> MAX");
	else
		level->SetText(std::to_wstring(skill->GetLevel()) + L" -> " + std::to_wstring(skill->GetLevel() + 1));
}
