#include "pch.h"
#include "SkillManager.h"
#include "Skill.h"
#include "TimeManager.h"

void SkillManager::Init()
{

}

void SkillManager::Update()
{
	for (auto skill : skills)
	{
		//엑티브 스킬은 활성화되어 있는 동안 실행되는 것이기 때문에
		//레벨업할 때만 갱신하면 된다.
		if (skill.second->IsActiveSkill()) continue;

		//쿨타임 돌기
		skill.second->curDelayTime += fDT;
		if (skill.second->curDelayTime > skill.second->maxDelayTime)
		{
			//쿨타임 다 돌았다면 스킬 쓰기
			skill.second->curDelayTime = 0.f;
			skill.second->OnUse(player);
		}
	}
}

void SkillManager::AddSkill(ESkillType type, Skill& skill)
{
	skills[type] = &skill;
}

void SkillManager::LevelUpSkill(ESkillType type)
{
	Skill* skill = skills[type];
	//활성화가 안되어 있다면
	if (skill->GetEnable() == false)
	{
		skill->SetEnable(true);
	}
	skill->OnLevelUp();
	skill->OnUse(player);
}