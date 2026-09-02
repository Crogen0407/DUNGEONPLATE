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
	for (auto& child : children)
		delete(child);
}

void Canvas::Update()
{
	
}

void Canvas::LateUpdate()
{
	if (enable == false) return;
	for (auto& child : children)
		child->LateUpdate();
}

void Canvas::Render(ComPtr<ID2D1RenderTarget> renderTarget)
{
	if (enable == false) return;

	for (auto& child : children)
	{
		if(child->GetActive())
			child->Render(renderTarget);
	}
}