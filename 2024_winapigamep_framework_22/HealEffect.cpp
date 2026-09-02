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
	Texture* texture = LOADTEXTURE(L"HealEffect", L"Texture\\Effect\\HealEffect.png");
	Vec2 texSize = { (float)texture->GetWidth() / 5, (float)texture->GetHeight() };
	_lifeTime = 0.2f;
	_animator = GetComponent<Animator>();
	_animator->CreateAnimation(L"Heal", texture, { 0.f,0.f }, texSize, { (float)texSize.x,0.f }, 5, _lifeTime / 5.f, false);
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

void HealEffect::OnPop()
{
	_animator->PlayAnimation(L"Heal", false);
}

void HealEffect::OnPush()
{
	Effect::OnPush();
}
