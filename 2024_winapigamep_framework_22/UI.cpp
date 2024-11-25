#include "pch.h"
#include "UI.h"
#include "Slider.h"
#include "Button.h"
#include "Image.h"
#include "Text.h"

UI::UI()
{
}

UI::~UI()
{
}


UI* UI::CreateUI(UIOPTION uiOption)
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

	return newInstance;
}

UI* UI::CreateUI(UIOPTION uiOption, Vec2 pos, Vec2 size)
{
	UI* newInstance = CreateUI(uiOption);
	newInstance->SetPos(pos);
	newInstance->SetSize(size);

	return newInstance;
}
