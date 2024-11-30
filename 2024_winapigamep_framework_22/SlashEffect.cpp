#include "pch.h"
#include "SlashEffect.h"
#include "SpriteRenderer.h"
#include "TimeManager.h"

SlashEffect::SlashEffect()
{
	AddComponent<SpriteRenderer>();
	_spriteRenderer = GetComponent<SpriteRenderer>();
	_spriteRenderer->SetTexture(L"SlashEffect", L"Texture\\Effect\\SlashEffect.bmp");
	SetSize({ 100, 100 });
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
	Effect::Update();
	AddPos(_dir * 120.f * fDT);
	Vec2 size = { 100, 100 };
	float effectSize = _curTime / _lifeTime * (size.x * 0.8f) + (size.x * 0.2f);
	int a = 0;
	SetSize({ effectSize, effectSize });
}

void SlashEffect::LateUpdate()
{
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
