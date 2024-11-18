#include "pch.h"
#include "AttackDirArrow.h"
#include "GDISelector.h"
#include "Object.h"
#include "InputManager.h"

AttackDirArrow::AttackDirArrow()
	: parent(nullptr)
{
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
	Vec2 attackDir = mousePos - parent->GetPos();
	attackDir.Normalize();

	float distance = 30;

	Vec2 selfPos = (attackDir * distance) + parent->GetPos();

	SetPos(selfPos);
}

void AttackDirArrow::Render(HDC _hdc)
{
	GDISelector gdi = GDISelector(_hdc, BRUSH_TYPE::RED);
	GDISelector gdi2 = GDISelector(_hdc, PEN_TYPE::RED);
	::ELLIPSE_RENDER(_hdc, GetPos().x, GetPos().y, 15, 15);
}
