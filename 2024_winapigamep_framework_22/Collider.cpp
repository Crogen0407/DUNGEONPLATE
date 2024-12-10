#include "pch.h"
#include "Collider.h"
#include "Object.h"
#include "GDISelector.h"
UINT Collider::m_sNextID = 0;
Collider::Collider()
	: m_vSize(30.f, 30.f)
	, m_vLatePos(-110.f, -110.f)
	, m_vOffsetPos(0.f, 0.f)
	, m_ID(m_sNextID++)
{
}

Collider::~Collider()
{
}

void Collider::LateUpdate()
{
	const Object* pOwner = GetOwner();
	Vec2 vPos = pOwner->GetPos();
	m_vLatePos = vPos + m_vOffsetPos;
}

void Collider::Render(HDC _hdc)
{
	if (m_showDebug == false) return;

	PEN_TYPE ePen = PEN_TYPE::RED;
	GDISelector pen(_hdc, ePen);
	GDISelector brush(_hdc, BRUSH_TYPE::HOLLOW);
	RECT_RENDER(_hdc, m_vLatePos.x, m_vLatePos.y,
		m_vSize.x, m_vSize.y);
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
;