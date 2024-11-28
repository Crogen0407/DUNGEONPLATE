#include "pch.h"
#include "PlayerHealthCompo.h"
#include "TimeManager.h"

PlayerHealthCompo::PlayerHealthCompo() :
	subHp(100),
	maxSubHp(100)
{

}

PlayerHealthCompo::~PlayerHealthCompo()
{
}

void PlayerHealthCompo::ApplyDamage(int value)
{
	isTakedDamage = true;
	int temp = value;
	SetSubHp((int)std::clamp(value - subHp, 0.f, maxSubHp));
	subHp -= value;
	if (value <= 0) return;
	HealthCompo::ApplyDamage(value);
}

void PlayerHealthCompo::LateUpdate()
{
	if (subHp >= maxSubHp) return;
	curDelay += fDT;
	if (isTakedDamage)
	{
		if (curDelay < 5.f) return;
		curDelay = 0.f;
		isTakedDamage = false;
	}
	else
	{
		if (curDelay < 1.f) return;
		curDelay = 0.f;
		SetSubHp(subHp + 1);
	}
}
