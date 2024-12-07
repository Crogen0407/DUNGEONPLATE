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
	Texture* texture = LOADTEXTURE(L"HitEffect", L"Texture\\Effect\\HitEffect.bmp");
	Vec2 texSize = { (int)texture->GetWidth() / 5, (int)texture->GetHeight() };
	_lifeTime = 0.2f;
	_animator = GetComponent<Animator>();
	_animator->CreateAnimation(L"HitEffect", texture, { 0,0 }, texSize, { (int)texSize.x,0 }, 5, _lifeTime / 4.f, false);
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

void HitEffect::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void HitEffect::OnPop()
{
	_animator->PlayAnimation(L"HitEffect", false);
}

void HitEffect::OnPush()
{
	Effect::OnPush();
}
