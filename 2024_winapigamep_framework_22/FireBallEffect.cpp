#include "pch.h"
#include "FireBallEffect.h"
#include "SpriteRenderer.h"
#include "TimeManager.h";
#include "PoolManager.h";
#include "Collider.h";
#include "SceneManager.h";
#include "HealthCompo.h";

FireBallEffect::FireBallEffect()
{
	AddComponent<Collider>();
	AddComponent<SpriteRenderer>();

	_spriteRenderer = GetComponent<SpriteRenderer>();
	_spriteRenderer->isRotatable = true;
	_lifeTime = 4.f;
}

FireBallEffect::~FireBallEffect()
{
}

void FireBallEffect::OnPop()
{
}

void FireBallEffect::OnPush()
{
	_curTime = 0;
}

void FireBallEffect::Update()
{
	_spriteRenderer->LookAt(_moveDir);
	_curTime += fDT;
	if (_curTime > _lifeTime)
		PUSH(L"FireBallEffect", this);
	Vec2 moveDir = _moveDir * _speed * fDT;
	AddPos(moveDir);
}

void FireBallEffect::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void FireBallEffect::EnterCollision(Collider* _other)
{
	//Object::EnterCollision(_other);
	LAYER layer = GET_SINGLE(SceneManager)->GetCurrentScene()->GetLayer(_other->GetOwner());

	if (layer == LAYER::PLAYER)
	{
		return;
	}

	HealthCompo* health = _other->GetOwner()->GetComponent<HealthCompo>();

	if (health != nullptr)
	{
		health->ApplyDamage(_damage);
		PUSH(L"FireBallEffect", this);
	}
}

void FireBallEffect::SetDir(const Vec2& dir)
{
	_moveDir = dir;
	SpriteRenderer* spriteRenderer = GetComponent<SpriteRenderer>();
	spriteRenderer->LookAt(_moveDir);
}

void FireBallEffect::SetMode(const EFireBallModeType& mode)
{
	SpriteRenderer* spriteRenderer = GetComponent<SpriteRenderer>();
	switch (mode)
	{
	case EFireBallModeType::FireBall_S:
		SetSize({ 32, 32 });
		GetComponent<Collider>()->SetSize({ 32, 32 });
		spriteRenderer->SetTexture(L"FireBall_S", L"Texture\\Effect\\FireBall_S.bmp");
		break;
	case EFireBallModeType::FireBall_M:
		SetSize({ 39, 39 });
		GetComponent<Collider>()->SetSize({ 39, 39 });
		spriteRenderer->SetTexture(L"FireBall_M", L"Texture\\Effect\\FireBall_M.bmp");
		break;
	case EFireBallModeType::FireBall_L:
		SetSize({ 60, 60 });
		GetComponent<Collider>()->SetSize({ 60, 60 });
		spriteRenderer->SetTexture(L"FireBall_L", L"Texture\\Effect\\FireBall_L.bmp");
		break;
	}
}
