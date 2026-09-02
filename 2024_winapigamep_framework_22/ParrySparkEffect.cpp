#include "pch.h"
#include "ParrySparkEffect.h"
#include "ResourceManager.h"
#include "PoolManager.h"
#include "TimeManager.h"
#include "EventManager.h"
#include "Texture.h"
#include "Animator.h"

ParrySparkEffect::ParrySparkEffect()
{
	AddComponent<Animator>();
	SetSize({ 100,100 });
	Texture* texture = LOADTEXTURE(L"ParrySparkEffect", L"Texture\\Effect\\ParrySparkEffect.png");
	Vec2 texSize = { (float)texture->GetWidth() / 4, (float)texture->GetHeight() };
	_lifeTime = 0.2f;
	_animator = GetComponent<Animator>();
	_animator->CreateAnimation(L"ParrySpark", texture, { 0.f,0.f }, texSize, { (float)texSize.x,0.f }, 4, _lifeTime/4.f, false);
}

ParrySparkEffect::~ParrySparkEffect()
{
}

void ParrySparkEffect::Update()
{
	_curTime += fDT;
	if (_curTime >= _lifeTime)
	{
		PUSH(L"ParrySparkEffect", this);
	}
}

void ParrySparkEffect::OnPop()
{
	_animator->PlayAnimation(L"ParrySpark", false);
}

void ParrySparkEffect::OnPush()
{
	Effect::OnPush();
}
