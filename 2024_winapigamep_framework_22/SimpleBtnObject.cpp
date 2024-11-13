#include "pch.h"
#include "SimpleBtnObject.h"
#include "Button.h"

SimpleBtnObject::SimpleBtnObject()
{
	this->AddComponent<Button>();
	Button* btn = GetComponent<Button>();

	//btn->Init();
}

SimpleBtnObject::~SimpleBtnObject()
{
}

void SimpleBtnObject::Update()
{
}

void SimpleBtnObject::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}
