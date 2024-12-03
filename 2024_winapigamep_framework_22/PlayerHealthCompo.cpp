#include "pch.h"
#include "PlayerHealthCompo.h"
#include "TimeManager.h"
#include "FadeManager.h"

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
	value -= subHp;
	if (value < 0)
		value = 0;
	SetSubHp((int)std::clamp(subHp - temp, 0.f, maxSubHp));
	HealthCompo::ApplyDamage(value);
}

void PlayerHealthCompo::OnDie()
{
	if (_isDie) return;
	HealthCompo::OnDie();
	_isDie = true;
	GET_SINGLE(FadeManager)->LoadScene(L"GameOverScene");
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
		SetSubHp(subHp + 10);
	}
}
