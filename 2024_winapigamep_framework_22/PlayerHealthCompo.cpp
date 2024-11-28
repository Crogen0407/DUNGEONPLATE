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
	if (subHp > 0)
	{
		SetSubHp(subHp - value);
		ChangeSubHpEvent.Invoke(subHp/maxSubHp);
	}
	else
	{
		HealthCompo::ApplyDamage(value);
	}
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
