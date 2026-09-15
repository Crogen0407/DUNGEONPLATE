#include "pch.h"
#include "HealthCompo.h"
#include "Object.h"
#include "ResourceManager.h"
#include "PoolManager.h"
#include "Core.h"

HealthCompo::HealthCompo() :
	hp(100),
	maxHp(100)
{
	GET_MANAGER(ResourceManager)->LoadSound(L"Hit", L"Sound\\Hit.wav", SOUND_CHANNEL::EFFECT2);
	GET_MANAGER(ResourceManager)->LoadSound(L"Heal", L"Sound\\Heal.wav", SOUND_CHANNEL::EFFECT2);

	GET_SINGLE(Core)->GetRenderTarget()->CreateSolidColorBrush(D2D1::ColorF(0x0f380f), _backBrush.GetAddressOf());
	GET_SINGLE(Core)->GetRenderTarget()->CreateSolidColorBrush(D2D1::ColorF(0x8bac0f), _fillBrush.GetAddressOf());
}

HealthCompo::~HealthCompo()
{
}

void HealthCompo::ApplyDamage(int value)
{
	Vec2 pos = GetOwner()->GetPosition();
	GET_MANAGER(ResourceManager)->Play(L"Hit");
	POP(L"HitEffect", pos);
	SetHp(hp - value);
	DamagedEvent.Invoke(NULL);
	if (hp <= 0)
	{
		OnDie();
	}
}

void HealthCompo::ApplyHeal(unsigned __int8 value)
{
	Vec2 pos = GetOwner()->GetPosition();
	POP(L"HealEffect", pos);
	GET_MANAGER(ResourceManager)->Play(L"Heal");
	SetHp(hp + value);
}

void HealthCompo::LateUpdate()
{
	
}

void HealthCompo::Render(ComPtr<ID2D1RenderTarget> renderTarget)
{
	if (hpBarActive == false) return;

	Vec2 pos = GetOwner()->GetPosition();
	pos.y += offsetY;
	Vec2 size = { GetOwner()->GetSize().x, 8.f};

	//Back
	renderTarget->DrawRectangle(D2D1::RectF(
		pos.x - size.x / 2, 
		pos.y - size.y / 2, 
		pos.x + size.x / 2, 
		pos.y + size.y / 2), 
		_backBrush.Get(), 3.f);

	renderTarget->FillRectangle(D2D1::RectF(
		pos.x - size.x / 2,
		pos.y - size.y / 2,
		pos.x + size.x / 2,
		pos.y + size.y / 2),
		_backBrush.Get());

	//Fill
	renderTarget->FillRectangle(D2D1::RectF(
		pos.x - size.x / 2,
		pos.y - size.y / 2,
		pos.x + (size.x / 2) * ((std::clamp(hp / maxHp, 0.f, 1.f)) * 2 - 1),
		pos.y + size.y / 2),
		_fillBrush.Get());
}
