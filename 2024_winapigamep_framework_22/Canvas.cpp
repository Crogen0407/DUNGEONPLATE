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
	for (auto child : children)
		child->LateUpdate();
}

void Canvas::Render(HDC _hdc)
{
	for (auto child : children)
		child->Render(_hdc);
}

UI* Canvas::CreateUI(UIOPTION uiOption)
{
	UI* newInstance = nullptr;
	switch (uiOption)
	{
	case UIOPTION::BUTTON:
		newInstance = new Button;
		break;
	case UIOPTION::IMAGE:
		newInstance = new Image;
		break;
	case UIOPTION::SLIDER:
		newInstance = new Slider;
		break;
	case UIOPTION::TEXT:
		newInstance = new Text;
		break;
	}
	newInstance->SetOwner(this);
	return newInstance;
}

UI* Canvas::CreateUI(UIOPTION uiOption, Vec2 pos, Vec2 size)
{
	UI* newInstance = CreateUI(uiOption);
	newInstance->SetPos(pos);
	newInstance->SetSize(size);

	return newInstance;
}
