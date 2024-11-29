#include "pch.h"
#include "SlashEffect.h"
#include "TimeManager.h"
#include "PoolManager.h"

SlashEffect::SlashEffect()
{
	SetTexture(L"SlashEffect", L"Texture\\Effect\\SlashEffect.bmp");
}

SlashEffect::~SlashEffect()
{
}

void SlashEffect::OnPop()
{
	
}

void SlashEffect::OnPush()
{
	curTime = 0.f;
}

void SlashEffect::Update()
{
	curTime += fDT;
	if (curTime > lifeTime)
		PUSH(this);
}
