#include "pch.h"
#include "SlashEffect.h"
#include "SpriteRenderer.h"
#include "TimeManager.h"
#include "Effect.h"
#include "Object.h"
#include "PoolManager.h"

SlashEffect::SlashEffect()
{
	AddComponent<SpriteRenderer>();
	_spriteRenderer = GetComponent<SpriteRenderer>();
	_spriteRenderer->SetTexture(L"SlashEffect", L"Texture\\Effect\\SlashEffect.bmp");
	_lifeTime = 0.15f;
}
SlashEffect::~SlashEffect()
{
}

void SlashEffect::OnPop()
{
}

void SlashEffect::OnPush()
{
	Effect::OnPush();
}

void SlashEffect::Update()
{
	_curTime += fDT;
	if (_curTime >= _lifeTime)
	{
		PUSH(L"SlashEffect", this);
	}

	AddPos(_dir * 500.f * fDT);
	Vec2 size = { 75, 75 };
	float effectSize = EaseOutCirc(_curTime / _lifeTime) * (size.x * 0.8f) + (size.x * 0.2f);
	int a = 0;
	SetSize({ effectSize, effectSize });
}

void SlashEffect::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void SlashEffect::LookAt(const Vec2& dir)
{
	_dir = dir;
	_spriteRenderer->LookAt(dir);
}
