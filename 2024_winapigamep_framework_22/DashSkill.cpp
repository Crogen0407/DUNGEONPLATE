#include "pch.h"
#include "DashSkill.h"

DashSkill::DashSkill()
{
	nameText = L"대쉬";
	descriptionText = L"공격 기능은 없지만\n 회피용으론 아주 \n제격입니다!";
}

DashSkill::~DashSkill()
{
}

void DashSkill::OnUse(Player* player)
{
}
