#include "pch.h"
#include "Text.h"
#include "ResourceManager.h"
#include "Canvas.h"

Text::Text()
{
	iPitchAndFamily = TA_TOP | TA_LEFT;
	color = RGB(15, 56, 15);
}

Text::~Text()
{
	DeleteObject(pfont);
}

void Text::LateUpdate()
{
}

void Text::Render(HDC _hdc)
{
	if (_owner == nullptr) return;
	Vec2 pos = GetPos() + _owner->GetPos();
	if (_parent != nullptr)
		pos += _parent->GetPos();

	Vec2 size = GetSize();
	::SetTextColor(_hdc, color);
	HFONT oldFont = static_cast<HFONT>(SelectObject(_hdc, pfont));

	::SetBkMode(_hdc, 1);
	RECT rect = { pos.x - size.x / 2, pos.y - size.y / 2, pos.x + size.x / 2, pos.y + size.y / 2 };  // 출력할 영역

	::DrawText(_hdc, text.c_str(), -1, &rect, iPitchAndFamily);

	SetTextColor(_hdc, RGB(0, 0, 0));
	SelectObject(_hdc, oldFont);
}

void Text::LoadFont(std::wstring fontName, int fontWidth, int fontHegith)
{
	GET_SINGLE(ResourceManager)->AddFont(fontName);
	pfont = CreateFont(fontHegith, fontWidth,
		0, 0, 0, 0, 0, 0, HANGEUL_CHARSET,
		0, 0, 0, VARIABLE_PITCH | FF_ROMAN, fontName.c_str());
}
