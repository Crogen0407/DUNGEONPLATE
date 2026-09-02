#include "pch.h"
#include "HitEffect.h"
#include "ResourceManager.h"
#include "PoolManager.h"
#include "TimeManager.h"
#include "EventManager.h"
#include "Texture.h"
#include "Animator.h"

HitEffect::HitEffect()
{
	AddComponent<Animator>();
	SetSize({ 120,120 });
	Texture* texture = LOADTEXTURE(L"HitEffect", L"Texture\\Effect\\HitEffect.png");
	Vec2 texSize = { (float)texture->GetWidth() / 5, (float)texture->GetHeight() };
	_lifeTime = 0.2f;
	_animator = GetComponent<Animator>();
	_animator->CreateAnimation(L"HitEffect", texture, { 0.f,0.f }, texSize, { (float)texSize.x,0.f }, 5, _lifeTime / 4.f, false);
}

HitEffect::~HitEffect()
{
}

void HitEffect::Update()
{
	_curTime += fDT;
	if (_curTime >= _lifeTime)
	{
		PUSH(L"HitEffect", this);
	}
}

void HitEffect::OnPop()
{
	_animator->PlayAnimation(L"HitEffect", false);
}

void HitEffect::OnPush()
{
	Effect::OnPush();
}
