#include "pch.h"
#include "AttackDirArrow.h"
#include "GDISelector.h"
#include "Object.h"
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
	SetPos({ parent->GetPos().x, parent->GetPos().y - 30 });
}

void AttackDirArrow::Render(HDC _hdc)
{
	GDISelector(_hdc, PEN_TYPE::BLUE);
	::RECT_RENDER(_hdc, GetPos().x, GetPos().y, 15, 15);
}
