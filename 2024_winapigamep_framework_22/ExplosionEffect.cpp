#include "pch.h"
#include "ExplosionEffect.h"
#include "ResourceManager.h"
#include "PoolManager.h"
#include "TimeManager.h"
#include "EventManager.h"
#include "Texture.h"
#include "Animator.h"

ExplosionEffect::ExplosionEffect(wstring name)
{
	_curTime = TIME;
	SetSize({ 100,100 });
	Texture* texture = LOADTEXTURE(name, L"Texture\\Effect\\" + name + L".bmp");
	Vec2 texSize = { (int)texture->GetWidth() / 4, (int)texture->GetHeight() };

	AddComponent<Animator>();

	GetComponent<Animator>()
		->CreateAnimation(L"Explosion", texture, { 0,0 }, texSize, { (int)texSize.x,0 }, 4, 0.1f, false);
	GetComponent<Animator>()->PlayAnimation(L"Explosion", true);
}

ExplosionEffect::~ExplosionEffect()
{
}

void ExplosionEffect::Update()
{
	if (_curTime + _lifeTime < TIME)
		GET_SINGLE(EventManager)->DeleteObject(this);
}

void ExplosionEffect::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}