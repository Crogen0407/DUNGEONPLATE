#include "pch.h"
#include "Collider.h"
#include "Object.h"
#include "GDISelector.h"
UINT Collider::_nextID = 0;
Collider::Collider()
	: _size(30.f, 30.f)
	, _latePosition(-110.f, -110.f)
	, _offsetPosition(0.f, 0.f)
	, _id(_nextID++)
{
}

Collider::~Collider()
{
}

void Collider::LateUpdate()
{
	const Object* pOwner = GetOwner();
	Vec2 vPos = pOwner->GetPosition();
	_latePosition = vPos + _offsetPosition;
}

void Collider::EnterCollision(Collider* _other)
{
	GetOwner()->EnterCollision(_other);
}

void Collider::StayCollision(Collider* _other)
{
	GetOwner()->StayCollision(_other);
}

void Collider::ExitCollision(Collider* _other)
{
	GetOwner()->ExitCollision(_other);
}