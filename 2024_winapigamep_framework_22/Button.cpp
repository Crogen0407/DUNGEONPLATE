#include "pch.h"
#include "Button.h"
#include "Texture.h"
#include "Object.h"
#include "InputManager.h"
#include "GDISelector.h"
#include "ResourceManager.h"

Button::Button() :
	m_curTex(nullptr),
	m_defaultTex(nullptr),
	m_selectedTex(nullptr),
	m_pressedTex(nullptr)
	
{
	m_defaultTex = GET_SINGLE(ResourceManager)->TextureLoad(L"UI", L"Texture\\UI.bmp");
	m_selectedTex = GET_SINGLE(ResourceManager)->TextureLoad(L"UI", L"Texture\\UI.bmp");
	m_curTex = m_defaultTex;
}

Button::~Button()
{
}

void Button::Init(Texture* defultTex, Texture* selectedTex, Texture* pressedTex)
{
	m_defaultTex = defultTex;
	m_selectedTex = selectedTex;
	m_pressedTex = pressedTex;
}

void Button::OnClick()
{
	m_curTex = m_pressedTex;
}

void Button::OnSelectEnter()
{
	m_curTex = m_selectedTex;
}

void Button::OnSelectExit()
{
	m_curTex = m_defaultTex;
}

void Button::LateUpdate()
{
	Vec2 pos = GetOwner()->GetPos();
	Vec2 size = GetOwner()->GetSize();

	Vec2 mousePos = GET_MOUSEPOS;

	if (pos.y + (size.y / 2) > mousePos.y &&
		pos.x + (size.x / 2) > mousePos.x &&
		pos.y - (size.y / 2) < mousePos.y &&
		pos.x - (size.x / 2) < mousePos.x) //마우스가 닿았는지
	{
		if (m_isSelected == false)
		{
			m_isSelected = true;
			OnSelectEnter();
		}
		if (GET_KEYDOWN(KEY_TYPE::LBUTTON) || GET_KEYDOWN(KEY_TYPE::RBUTTON))
		{
			OnClick();
		}
	}
	else
	{
		if (m_isSelected == true)
		{
			m_isSelected = false;
			OnSelectExit();
		}
	}
}

void Button::Render(HDC _hdc)
{
	Vec2 pos = GetOwner()->GetPos();
	Vec2 size = GetOwner()->GetSize();

	if (m_showDebug)
	{
		PEN_TYPE ePen = PEN_TYPE::RED;
		GDISelector pen(_hdc, ePen);
		GDISelector brush(_hdc, BRUSH_TYPE::HOLLOW);
		RECT_RENDER(_hdc, pos.x, pos.y,
			size.x, size.y);
	}

	if (m_curTex == nullptr) return;

	TransparentBlt(_hdc,
		(int)(pos.x) - 24,
		(int)(pos.y) - 24,
		(int)48,
		(int)48,
		m_curTex->GetTexDC(),
		0,
		0,
		48,
		48,
		RGB(255, 0, 255));
}
