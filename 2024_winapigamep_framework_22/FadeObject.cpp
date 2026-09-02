#include "pch.h"
#include "FadeObject.h"
#include "SpriteRenderer.h"
#include "Animator.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "SceneManager.h"
#include "TimeManager.h"

FadeObject::FadeObject()
{
	AddComponent<SpriteRenderer>();
	_spriteRenderer = GetComponent<SpriteRenderer>();

	_screenTransitionTexture = LOADTEXTURE(L"ScreenTransition", L"Texture\\Effect\\ScreenTransition.png");

	_spriteRenderer->SetTexture(_screenTransitionTexture);
	_spriteRenderer->enable = false;
}

FadeObject::~FadeObject()
{
}

void FadeObject::Update()
{
	float max;
	if (SCREEN_WIDTH > SCREEN_HEIGHT) max = SCREEN_WIDTH * 2.75f;
	else max = SCREEN_HEIGHT * 2.75f;
	SetSize({ max, max });

	if (_fadeDuration > _fadeTimer)
		_fadeTimer += fUNSCALEDDT;
	else return;

	float percent = _fadeTimer / _fadeDuration;
	Vec2 center = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	
	percent = (__int8)(percent * 16.f) / 16.f;
	Vec2 offset = _isFadeIn ?
		Vec2::Lerp(Vec2::Zero, Vec2(- SCREEN_WIDTH, -SCREEN_HEIGHT)*1.75f, percent) :
		Vec2::Lerp(Vec2(SCREEN_WIDTH, SCREEN_HEIGHT)*1.75f, Vec2::Zero, percent);

	Vec2 finalPos = center + offset;
	SetPosition(finalPos);
}

void FadeObject::FadeIn()
{
	_isFadeIn = true;
	_fadeTimer = 0.f;
	_spriteRenderer->enable = true;
}

void FadeObject::FadeOut()
{
	_isFadeIn = false;
	_fadeTimer = 0.f;
	_spriteRenderer->enable = true;
}