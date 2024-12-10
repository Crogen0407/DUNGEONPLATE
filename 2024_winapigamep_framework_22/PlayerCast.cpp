#include "pch.h"
#include "PlayerCast.h"
#include "Collider.h"

PlayerCast::PlayerCast()
{
	AddComponent<Collider>();
	_collider = GetComponent<Collider>();
	_collider->SetSize({ 5, 5 });
}

PlayerCast::PlayerCast(float startAngle)
{
	AddComponent<Collider>();
	_startAngle = startAngle;
	_collider = GetComponent<Collider>();
	_collider->SetSize({ 5, 5 });
}

PlayerCast::~PlayerCast()
{
}

void PlayerCast::Update()
{
}

void PlayerCast::LateUpdate()
{
	Object::LateUpdate();
}

void PlayerCast::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void PlayerCast::EnterCollision(Collider* _other)
{    
	other = _other;
	_isCast = true;
}

void PlayerCast::StayCollision(Collider* _other)
{
	_isCast = true;
}

void PlayerCast::ExitCollision(Collider* _other)
{
	_isCast = false;
}

void PlayerCast::SetMoveDir(Vec2 dir)
{
	_dir = dir;
	float angle = (_startAngle * Deg2Rad);
	_dir.x = _dir.x * cosf(angle) - _dir.y * sinf(angle);
	_dir.y = _dir.x * sinf(angle) + _dir.y * cosf(angle);
	_collider->SetOffSetPos(_dir * _distance);
}
