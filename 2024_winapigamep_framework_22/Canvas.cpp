#include "pch.h"
#include "UI.h"
#include "Canvas.h"
#include "Slider.h"
#include "Button.h"
#include "Image.h"
#include "Text.h"

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
	for (auto& child : children)
		child->LateUpdate();
}

void Canvas::Render(HDC _hdc)
{
	for (auto& child : children)
	{
		if(child->GetActive())
			child->Render(_hdc);
	}
}