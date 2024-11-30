#pragma once
#include "Button.h"
#include "Text.h"
#include "Skill.h";

struct SkillSlot
{
public:
	SkillSlot() = default;
	~SkillSlot()
	{
		delete(base);
		delete(name);
		delete(description);
	}
public:
	void Init(Skill* skill) {
		this->skill = skill;
		name->SetText(skill->GetNameText());
		description->SetText(skill->GetDescriptionText());
		if (skill->GetLevel() == 0)
			level->SetText(L"NEW!");
		else if(skill->GetLevel() == 9)
			level->SetText(std::to_wstring(skill->GetLevel()) + L" -> MAX");
		else
			level->SetText(std::to_wstring(skill->GetLevel()) + L" -> " + std::to_wstring(skill->GetLevel()+1));
	}
public:
	Button* base = nullptr;
	Text* name = nullptr;
	Text* level = nullptr;
	Text* description = nullptr;
public:
	Skill* skill;
	Vec2 pos;
	Vec2 size;
};