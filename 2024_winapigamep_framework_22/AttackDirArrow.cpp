#include "pch.h"
#include "AttackDirArrow.h"
#include "Object.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "SpriteRenderer.h"
#include "TimeManager.h"

AttackDirArrow::AttackDirArrow()
	: parent(nullptr),
	m_defaultTex(nullptr),
	spriteRenderer(nullptr)
{
	AddComponent<SpriteRenderer>();
	spriteRenderer = GetComponent<SpriteRenderer>();
	spriteRenderer->SetTexture(L"Arrow", L"Texture\\Arrow.bmp");
	spriteRenderer->SetAngle(PI);
	SetSize({ 12, 12 });
}

AttackDirArrow::~AttackDirArrow()
{
}

void AttackDirArrow::SetParent(Object* parent)
{
	this->parent = parent;
}

void AttackDirArrow::Update()
{
	if (parent == nullptr) return;
	if (TIMESCALE == 0) return;
	Vec2 mousePos = GET_MOUSEPOS;
	dir = mousePos - parent->GetPos();
	dir.Normalize();

	float distance = 30;

	Vec2 selfPos = (dir * distance) + parent->GetPos();

	float angle = atan2(dir.y, dir.x);

	spriteRenderer->LookAt(dir);
	SetPos(selfPos);
}

void AttackDirArrow::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}