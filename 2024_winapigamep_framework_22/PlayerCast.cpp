#include "pch.h"
#include "PlayerCast.h"
#include "Collider.h"
#include "DashSkill.h"
#include "SkillManager.h"

PlayerCast::PlayerCast()
{
	AddComponent<Collider>();
	_collider = GetComponent<Collider>();
	_collider->SetSize({ 10, 10 });
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
	_collider->SetOffSetPos(_dir * _distance);
	_dir = dir;
}
