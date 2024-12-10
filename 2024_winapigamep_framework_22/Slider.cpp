#include "pch.h"
#include "Slider.h"
#include "Canvas.h"
#include "Texture.h"

Slider::Slider()
{
	fillColor = RGB(139, 172, 15);
	backColor = RGB(48, 98, 48);
	value = 1.f;
}

Slider::~Slider()
{
}

void Slider::LateUpdate()
{
}

void Slider::Render(HDC _hdc)
{
	if (_owner == nullptr) return;
	Vec2 pos = GetPos() + _owner->GetPos();
	if (_parent != nullptr)
		pos += _parent->GetPos();

	Vec2 size = GetSize();
	backBrush = ::CreateSolidBrush(backColor);

	HPEN myPen = CreatePen(PS_NULL, 0, RGB(255, 255, 255));
	HPEN oldPen = static_cast<HPEN>(::SelectObject(_hdc, myPen));
	HBRUSH oldBackBrush = static_cast<HBRUSH>(::SelectObject(_hdc, backBrush));

	//BackTexture
	::Rectangle(_hdc,
		(int)(pos.x) - size.x / 2,
		(int)(pos.y) - size.y / 2,
		(int)(pos.x) + size.x / 2,
		(int)(pos.y) + size.y / 2);

	::SelectObject(_hdc, oldBackBrush);
	::DeleteObject(backBrush);

	fillBrush = ::CreateSolidBrush(fillColor);
	HBRUSH oldFillBrush = static_cast<HBRUSH>(::SelectObject(_hdc, fillBrush));

	if (isVertical)
	{
		valueVec.x = 1;
		valueVec.y = value * 2 - 1;
	}
	else
	{
		valueVec.x = value * 2 - 1;
		valueVec.y = 1;
	}

	if (flip)
	{
		//FillTexture
		::Rectangle(_hdc,
			(int)pos.x - (size.x * valueVec.x) / 2 + offsetX / 2,
			(int)pos.y - (size.y * valueVec.y) / 2 + offsetY / 2,
			(int)pos.x + (size.x / 2) - offsetX / 2,
			(int)pos.y + (size.y / 2) - offsetY / 2);
	}
	else
	{
		//FillTexture
		::Rectangle(_hdc,
			(int)pos.x - (size.x / 2) + offsetX / 2,
			(int)pos.y - (size.y / 2) + offsetY / 2,
			(int)pos.x + (size.x * valueVec.x) / 2 - offsetX / 2,
			(int)pos.y + (size.y * valueVec.y) / 2 - offsetY / 2);
	}

	::SelectObject(_hdc, oldPen);
	::SelectObject(_hdc, oldFillBrush);
	::DeleteObject(myPen);
	::DeleteObject(oldBackBrush);
	::DeleteObject(fillBrush);
}
