#include "pch.h"
#include "HealPackSkill.h"
#include "Player.h"
#include "PlayerHealthCompo.h"

HealPackSkill::HealPackSkill() :
	healthCompo(nullptr)
{
	nameText = L"Èú ÆÑ";
	descriptionText = L"10ÃÊ ¸¶´Ù ÈúÀ» ¹ÞÀ» \n¼ö ÀÖ½À´Ï´Ù.";
}

HealPackSkill::~HealPackSkill()
{
}

void HealPackSkill::OnUse(Player* player)
{
	if (healthCompo == nullptr)
		healthCompo = player->GetComponent<PlayerHealthCompo>();
	
	healthCompo->ApplyHeal(healAmount);
}

void HealPackSkill::OnLevelUp(Player* player)
{
	Skill::OnLevelUp(player);
	healAmount += 3;
}
