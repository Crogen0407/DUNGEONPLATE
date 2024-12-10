#include "pch.h"
#include "HealthCompo.h"
#include "Object.h"
#include "ResourceManager.h"
#include "PoolManager.h"

HealthCompo::HealthCompo() :
	hp(100),
	maxHp(100),
	fillBrush(NULL),
	backBrush(NULL)
{
	fillBrush = ::CreateSolidBrush(RGB(139, 172, 15));
	backBrush = ::CreateSolidBrush(RGB(48, 98, 48));
	GET_SINGLE(ResourceManager)->LoadSound(L"Hit", L"Sound\\Hit.wav", SOUND_CHANNEL::EFFECT2);
	GET_SINGLE(ResourceManager)->LoadSound(L"Heal", L"Sound\\Heal.wav", SOUND_CHANNEL::EFFECT2);
}

HealthCompo::~HealthCompo()
{
	DeleteObject(fillBrush);
	DeleteObject(backBrush);
}

void HealthCompo::ApplyDamage(int value)
{
	Vec2 pos = GetOwner()->GetPos();
	GET_SINGLE(ResourceManager)->Play(L"Hit");
	POP(L"HitEffect", pos);
	SetHp(hp - value);
	DamagedEvent.Invoke(NULL);
	if (hp <= 0)
	{
		OnDie();
	}
}

void HealthCompo::ApplyHeal(int value)
{
	Vec2 pos = GetOwner()->GetPos();
	POP(L"HealEffect", pos);
	GET_SINGLE(ResourceManager)->Play(L"Heal");
	SetHp(hp + value);
}

void HealthCompo::LateUpdate()
{
	
}

void HealthCompo::Render(HDC hdc)
{
	if (hpBarActive == false) return;

	Vec2 pos = GetOwner()->GetPos();
	pos.y += offsetY;
	Vec2 size = { GetOwner()->GetSize().x, 12.f};

	//Back
	HBRUSH oldBrush = static_cast<HBRUSH>(::SelectObject(hdc, backBrush));
	::Rectangle(hdc,
		pos.x - size.x / 2,
		pos.y - size.y / 2,
		pos.x + size.x/2,
		pos.y + size.y/2);

	//Fill
	static_cast<HBRUSH>(::SelectObject(hdc, fillBrush));

	::Rectangle(hdc,
		pos.x - size.x / 2,
		pos.y - size.y / 2,
		(pos.x + (size.x / 2)*(std::clamp(hp / maxHp, 0.f, 1.f)*2-1)),
		pos.y + size.y / 2);

	::SelectObject(hdc, oldBrush);
}
