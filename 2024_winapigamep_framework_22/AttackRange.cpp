#include "pch.h"
#include "AttackRange.h"
#include "SpriteRenderer.h"

AttackRange::AttackRange()
{
	AddComponent<SpriteRenderer>();
	_spriteRenderer = GetComponent<SpriteRenderer>();
	_spriteRenderer->SetTexture(L"AttackRange", L"Texture\\AttackRange.bmp");
	_spriteRenderer->enable = true;
	SetSize({ 110, 110 });
}

AttackRange::~AttackRange()
{
}

void AttackRange::Update()
{
	SetPos(parent->GetPos());
}

void AttackRange::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void AttackRange::SetDir(Vec2 dir)
{
	_spriteRenderer->LookAt(dir);
}
