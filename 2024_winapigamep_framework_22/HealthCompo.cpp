#include "pch.h"
#include "HealthCompo.h"

HealthCompo::HealthCompo() :
	hp(100),
	maxHp(100)
{
}

HealthCompo::~HealthCompo()
{
}

void HealthCompo::ApplyDamage(int value)
{
	SetHp(hp - value);

	if (hp <= 0)
	{
		OnDie();
	}
}

void HealthCompo::ApplyHeal(int value)
{
	SetHp(hp + value);
}