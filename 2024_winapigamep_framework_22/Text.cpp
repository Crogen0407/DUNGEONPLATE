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
	Vec2 pos = GetPos() + owner->GetPos();
	::SetTextColor(_hdc, color);
	HFONT oldFont = static_cast<HFONT>(SelectObject(_hdc, pfont));

	::SetBkMode(_hdc, 1);
	::SetTextAlign(_hdc, iPitchAndFamily);
	RECT rect = { pos.x - GetSize().x / 2, pos.y - GetSize().y / 2, pos.x + GetSize().x / 2, pos.y + GetSize().y / 2 };  // 출력할 영역

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
