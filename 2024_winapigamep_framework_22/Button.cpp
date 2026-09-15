#include "pch.h"
#include "Button.h"
#include "Texture.h"
#include "InputManager.h"
#include "GDISelector.h"
#include "ResourceManager.h"
#include "Canvas.h"
#include "FadeManager.h"

Button::Button() :
	_defaultTex(nullptr),
	_selectedTex(nullptr),
	_pressedTex(nullptr)
	
{
}

Button::~Button()
{
}

void Button::Init(Texture* defultTex, Texture* selectedTex, Texture* pressedTex)
{
	_defaultTex = defultTex;
	_selectedTex = selectedTex;
	_pressedTex = pressedTex;
}

void Button::OnClick()
{
	if (onlyOneCountClick)
	{
		if (_isClicked == true) return;
		_isClicked = true;
	}
	if(_pressedTex != nullptr)
		texture = _pressedTex;
	OnClickEvent.Invoke(NULL);
}

void Button::OnSelectEnter()
{
	if (_selectedTex != nullptr)
		texture = _selectedTex;

	LOADSOUND(L"ButtonSelect", L"Sound\\ButtonSelect.wav", SOUND_CHANNEL::EFFECT1);
	GET_MANAGER(ResourceManager)->Play(L"ButtonSelect");
	OnSelectEnterEvent.Invoke(NULL);
}

void Button::OnSelectExit()
{
	if (_defaultTex != nullptr)
		texture = _defaultTex;
	OnSelectExitEvent.Invoke(NULL);
}

void Button::LateUpdate()
{
	if (GET_MANAGER(FadeManager)->IsSceneFading()) return;
	if (_owner == nullptr) return;
	Vec2 pos = GetPosition() + _owner->GetPosition();
	if (_parent != nullptr)
		pos += _parent->GetPosition();

	Vec2 size = GetSize();

	Vec2 mousePos = GET_MOUSEPOS;

	if (pos.y + (size.y / 2) > mousePos.y &&
		pos.x + (size.x / 2) > mousePos.x &&
		pos.y - (size.y / 2) < mousePos.y &&
		pos.x - (size.x / 2) < mousePos.x) //마우스가 닿았는지
	{
		if (_isSelected == false)
		{
			_isSelected = true;
			OnSelectEnter();
		}
		if (GET_KEYDOWN(KEY_TYPE::LBUTTON) || GET_KEYDOWN(KEY_TYPE::RBUTTON))
		{
			OnClick();
		}
	}
	else
	{
		if (_isSelected == true)
		{
			_isSelected = false;
			OnSelectExit();
		}
	}
}

void Button::Render(ComPtr<ID2D1RenderTarget> renderTarget)
{
	Image::Render(renderTarget);

	if(_owner == nullptr) return;
	Vec2 pos = GetPosition() + _owner->GetPosition();
	if (_parent != nullptr)
		pos += _parent->GetPosition();

	Vec2 size = GetSize();
}