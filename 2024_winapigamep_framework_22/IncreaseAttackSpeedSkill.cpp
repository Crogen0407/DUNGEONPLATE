#include "pch.h"
#include "IncreaseAttackSpeedSkill.h"
#include "Player.h"

IncreaseAttackSpeedSkill::IncreaseAttackSpeedSkill()
{
	nameText = L"공격 속도 증가";
	descriptionText = L"좀 더 자주 공격할 \n수 있습니다.";
	isActiveSkill = true;
}

IncreaseAttackSpeedSkill::~IncreaseAttackSpeedSkill()
{
}

void IncreaseAttackSpeedSkill::OnUse(Player* player)
{
}

void IncreaseAttackSpeedSkill::OnLevelUp(Player* player)
{
	Skill::OnLevelUp(player);
	if (_originParryCoolTime == -1)
	{
		_originParryCoolTime = player->GetParryCoolTime();
		//이펙트 추가
	}

	player->SetParryCoolTime(_originParryCoolTime - ((_originParryCoolTime / 2) * level / 10.f));
	
}
