#include "pch.h"
#include "FireBallEffect.h"
#include "SpriteRenderer.h"
#include "TimeManager.h";
#include "PoolManager.h";
#include "Collider.h";

FireBallEffect::FireBallEffect()
{
	AddComponent<Collider>();
	AddComponent<SpriteRenderer>();
	_collider = GetComponent<Collider>();
	_spriteRenderer = GetComponent<SpriteRenderer>();
	_spriteRenderer->isRotatable = true;
	_lifeTime = 5.f;
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
	if (activeSelf == false) return;
	Object::EnterCollision(_other);
	//적들에게 데미지 입히는 거 넣기
	PUSH(L"FireBallEffect", this);
}

void FireBallEffect::SetDir(const Vec2& dir)
{
	_moveDir = dir;
	_spriteRenderer->LookAt(_moveDir);
}

void FireBallEffect::SetMode(const EFireBallModeType& mode)
{
	_spriteRenderer = GetComponent<SpriteRenderer>();
	switch (mode)
	{
	case EFireBallModeType::FireBall_S:
		SetSize({ 45, 45 });
		_spriteRenderer->SetTexture(L"FireBall_S", L"Texture\\Effect\\FireBall_S.bmp");
		break;
	case EFireBallModeType::FireBall_M:
		SetSize({ 50, 50 });
		_spriteRenderer->SetTexture(L"FireBall_M", L"Texture\\Effect\\FireBall_M.bmp");
		break;
	case EFireBallModeType::FireBall_L:
		SetSize({ 60, 60 });
		_spriteRenderer->SetTexture(L"FireBall_L", L"Texture\\Effect\\FireBall_L.bmp");
		break;
	}
	_collider->SetSize(GetSize());
}
