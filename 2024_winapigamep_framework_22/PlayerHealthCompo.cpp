#include "pch.h"
#include "PlayerHealthCompo.h"
#include "TimeManager.h"
#include "FadeManager.h"
#include "Object.h"
#include "GameManager.h"

PlayerHealthCompo::PlayerHealthCompo() :
	subHp(100),
	maxSubHp(100)
{
	SetOffsetY(40);
	hpBarActive = true;
}

PlayerHealthCompo::~PlayerHealthCompo()
{
}

void PlayerHealthCompo::ApplyDamage(int value)
{
	if (isInvincible) return;
	isTakedDamage = true;
	int temp = value;
	value -= subHp;
	if (value < 0)
		value = 0;
	SetSubHp((int)std::clamp(subHp - temp, 0.f, maxSubHp));

	//È­¸é Èçµé¸²
	GET_SINGLE(GameManager)->ShakeConsoleWindow(0.05f, 10, 90);

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

void PlayerHealthCompo::Render(HDC hdc)
{
	//HealthCompo::Render(hdc);

	//Vec2 pos = GetOwner()->GetPos();
	//Vec2 size = { GetOwner()->GetSize().x, 6.f };
	//pos.y += offsetY + size.y/2;

	////Back
	//HBRUSH oldBrush = static_cast<HBRUSH>(::SelectObject(hdc, backBrush));
	//::Rectangle(hdc,
	//	pos.x - size.x / 2,
	//	pos.y - size.y / 2,
	//	pos.x + size.x / 2,
	//	pos.y + size.y / 2);

	////Fill
	//static_cast<HBRUSH>(::SelectObject(hdc, fillBrush));

	//::Rectangle(hdc,
	//	pos.x - size.x / 2,
	//	pos.y - size.y / 2,
	//	(pos.x + (size.x / 2) * (std::clamp(subHp / maxSubHp, 0.f, 1.f) * 2 - 1)),
	//	pos.y + size.y / 2);

	//::SelectObject(hdc, oldBrush);
}
