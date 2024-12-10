#include "pch.h"
#include "HealItem.h"
#include "Player.h"
#include "PlayerHealthCompo.h"

HealItem::HealItem()
{
	nameText = L"하이 포션";
	descriptionText = L"즉시 20만큼 회복합니다.";
}

HealItem::~HealItem()
{
}

void HealItem::OnLevelUp(Player* player)
{
	player->GetComponent<PlayerHealthCompo>()->ApplyHeal(20);
}

void HealItem::OnUse(Player* player)
{
}
