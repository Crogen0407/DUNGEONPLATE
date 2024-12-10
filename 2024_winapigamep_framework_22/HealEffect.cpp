#include "pch.h"
#include "HealEffect.h"
#include "Animator.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "TimeManager.h"
#include "PoolManager.h"

HealEffect::HealEffect()
{
	AddComponent<Animator>();
	SetSize({ 100,100 });
	Texture* texture = LOADTEXTURE(L"HealEffect", L"Texture\\Effect\\HealEffect.bmp");
	Vec2 texSize = { (int)texture->GetWidth() / 5, (int)texture->GetHeight() };
	_lifeTime = 0.2f;
	_animator = GetComponent<Animator>();
	_animator->CreateAnimation(L"Heal", texture, { 0,0 }, texSize, { (int)texSize.x,0 }, 5, _lifeTime / 5.f, false);
}

HealEffect::~HealEffect()
{
}

void HealEffect::Update()
{
	_curTime += fDT;
	if (_curTime >= _lifeTime)
	{
		PUSH(L"HealEffect", this);
	}
}

void HealEffect::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void HealEffect::OnPop()
{
	_animator->PlayAnimation(L"Heal", false);
}

void HealEffect::OnPush()
{
	Effect::OnPush();
}
