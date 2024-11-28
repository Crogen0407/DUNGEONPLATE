#include "pch.h"
#include "IncreaseAttackSpeedSkill.h"

IncreaseAttackSpeedSkill::IncreaseAttackSpeedSkill()
{
	nameText = L"공격 속도 증가";
	descriptionText = L"좀 더 자주 공격할 \n수 있습니다.";
}

IncreaseAttackSpeedSkill::~IncreaseAttackSpeedSkill()
{
}

void IncreaseAttackSpeedSkill::OnUse(Player* player)
{
}
