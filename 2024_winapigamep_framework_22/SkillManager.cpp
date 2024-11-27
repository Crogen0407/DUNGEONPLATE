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
		//��Ƽ�� ��ų�� Ȱ��ȭ�Ǿ� �ִ� ���� ����Ǵ� ���̱� ������
		//�������� ���� �����ϸ� �ȴ�.
		if (skill.second->IsActiveSkill()) continue;

		//��Ÿ�� ����
		skill.second->curDelayTime += fDT;
		if (skill.second->curDelayTime > skill.second->maxDelayTime)
		{
			//��Ÿ�� �� ���Ҵٸ� ��ų ����
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
	//Ȱ��ȭ�� �ȵǾ� �ִٸ�
	if (skill->GetEnable() == false)
	{
		skill->SetEnable(true);
	}
	skill->OnLevelUp();
	skill->OnUse(player);
}