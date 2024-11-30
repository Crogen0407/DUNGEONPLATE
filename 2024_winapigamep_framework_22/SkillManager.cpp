#include "pch.h"
#include "SkillManager.h"
#include "TimeManager.h"
#include "Skill.h"
#include "HealPackSkill.h"
#include "IncreaseAttackSpeedSkill.h"
#include "IncreaseMaxHpSkill.h"
#include "IncreaseMoveSpeedSkill.h"
#include "DashSkill.h"

void SkillManager::Init()
{
	AddSkill(ESkillType::DashSkill,					static_cast<Skill*>(new DashSkill));
	AddSkill(ESkillType::HealPack,					static_cast<Skill*>(new HealPackSkill));
	AddSkill(ESkillType::IncreaseAttackSpeed,		static_cast<Skill*>(new IncreaseAttackSpeedSkill));
	AddSkill(ESkillType::IncreaseMaxHp,				static_cast<Skill*>(new IncreaseMaxHpSkill));
	AddSkill(ESkillType::IncreaseMoveSpeed,			static_cast<Skill*>(new IncreaseMoveSpeedSkill));
}

void SkillManager::Update()
{
	for (auto skill : skills)
	{
		//0레벨은 가지고 있지 않은 상태이다.
		if (skill.second->GetLevel() == 0) continue;
		skill.second->Update();
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
		skill.second->DelayTimeEvent.Invoke(skill.second->curDelayTime/ skill.second->maxDelayTime);
	}
}

const vector<Skill*> SkillManager::GetRendomSkills()
{
	int arr[(UINT)ESkillType::LAST];
	int lastNum = 0;
	for (int i = 0; i < (UINT)ESkillType::LAST; i++)
	{
		arr[i] = i;
		lastNum = i;
	}

	srand((unsigned int)TIME);

	for (int i = 0; i < 30; i++)
	{
		int dest = rand() % (UINT)ESkillType::LAST;
		int sour = rand() % (UINT)ESkillType::LAST;

		int temp = arr[dest];
		arr[dest] = arr[sour];
		arr[sour] = temp;
	}

	vector<Skill*> output;

	//만랩 제외
	for (int i = 0; i < (UINT)ESkillType::LAST; i++)
	{
		if (output.size() >= 3) break;
		if (skills[(ESkillType)arr[i]]->GetLevel() >= 10) continue;
		output.push_back(skills[(ESkillType)arr[i]]);
	}

	return output;
}

void SkillManager::AddSkill(ESkillType type, Skill* skill)
{
	skills[type] = skill;
}

void SkillManager::LevelUpSkill(ESkillType type)
{
	Skill* skill = skills[type];
	//활성화가 안되어 있다면
	if (skill->GetEnable() == false)
	{
		skill->SetEnable(true);
	}
	skill->OnLevelUp(player);
	skill->OnUse(player);
}