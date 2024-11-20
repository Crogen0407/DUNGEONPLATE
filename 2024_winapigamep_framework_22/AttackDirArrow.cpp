#include "pch.h"
#include "AttackDirArrow.h"
#include "GDISelector.h"
#include "Object.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "SpriteRenderer.h"

AttackDirArrow::AttackDirArrow()
	: parent(nullptr),
	m_defaultTex(nullptr),
	spriteRenderer(nullptr)
{
	m_defaultTex = GET_SINGLE(ResourceManager)->TextureLoad(L"dirArrow", L"Texture\\arrow.bmp");
	AddComponent<SpriteRenderer>();
	spriteRenderer = GetComponent<SpriteRenderer>();
	spriteRenderer->SetTexture(L"arrow", L"Texture/arrow.bmp");
	spriteRenderer->SetAngle(PI);
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

	Vec2 mousePos = GET_MOUSEPOS;
	dir = mousePos - parent->GetPos();
	dir.Normalize();

	float distance = 30;

	Vec2 selfPos = (dir * distance) + parent->GetPos();

	float angle = atan2(dir.y, dir.x);

	spriteRenderer->LookAt(dir);
	//spriteRenderer->LookAt(dir);
	SetPos(selfPos);
}

void AttackDirArrow::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}