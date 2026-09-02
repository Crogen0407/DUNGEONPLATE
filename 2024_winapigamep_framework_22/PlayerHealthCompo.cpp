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

void PlayerHealthCompo::Render(ComPtr<ID2D1RenderTarget> renderTarget)
{
	if (hpBarActive == false) return;

	Vec2 pos = GetOwner()->GetPosition();
	pos.y += offsetY;
	Vec2 size = { GetOwner()->GetSize().x + 2.0f, 13.5f };

	// Hp
	{
		//Back
		renderTarget->DrawRectangle(D2D1::RectF(
			pos.x - size.x / 2,
			pos.y - size.y * 0.75f,
			pos.x + size.x / 2,
			pos.y),
			_backBrush.Get(), 3.f);

		renderTarget->FillRectangle(D2D1::RectF(
			pos.x - size.x / 2,
			pos.y - size.y * 0.75f,
			pos.x + size.x / 2,
			pos.y),
			_backBrush.Get());

		//Fill
		renderTarget->FillRectangle(D2D1::RectF(
			pos.x - size.x / 2,
			pos.y - size.y * 0.75f,
			pos.x + (size.x / 2) * ((std::clamp(hp / maxHp, 0.f, 1.f)) * 2 - 1),
			pos.y),
			_fillBrush.Get());
	}

	// SubHp
	{
		//Back
		renderTarget->DrawRectangle(D2D1::RectF(
			pos.x - size.x / 2,
			pos.y,
			pos.x + size.x / 2,
			pos.y + size.y * 0.25f),
			_backBrush.Get(), 3.f);

		renderTarget->FillRectangle(D2D1::RectF(
			pos.x - size.x / 2,
			pos.y,
			pos.x + size.x / 2,
			pos.y + size.y * 0.25f),
			_backBrush.Get());

		//Fill
		renderTarget->FillRectangle(D2D1::RectF(
			pos.x - size.x / 2,
			pos.y,
			pos.x + (size.x / 2) * ((std::clamp(subHp / maxSubHp, 0.f, 1.f)) * 2 - 1),
			pos.y + size.y * 0.25f),
			_fillBrush.Get());
	}
}
