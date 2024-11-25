#include "pch.h"
#include "UI.h"
#include "Canvas.h"

Canvas::Canvas()
{
}

Canvas::~Canvas()
{
}

void Canvas::Update()
{
}

void Canvas::LateUpdate()
{
	for (auto child : children)
		child->LateUpdate();
}

void Canvas::Render(HDC _hdc)
{
	for (auto child : children)
		child->Render(_hdc);
}
