#include "pch.h"
#include "Text.h"
#include "ResourceManager.h"

Text::Text()
{
	iPitchAndFamily = TA_TOP | TA_LEFT;
	color = RGB(0, 0, 0);
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
	::SetTextColor(_hdc, color);
	HFONT oldFont = static_cast<HFONT>(SelectObject(_hdc, pfont));

	Vec2 pos = { GetPos().x - GetSize().x / 2 , GetPos().y - GetSize().y / 2 };
	::SetBkMode(_hdc, 1);
	::SetTextAlign(_hdc, iPitchAndFamily);
	::TextOut(_hdc, pos.x, pos.y, 
		text.c_str(), text.size());

	SetTextColor(_hdc, RGB(0, 0, 0));
	SelectObject(_hdc, oldFont);
}

void Text::LoadFont(std::wstring fontName, int fontWidth, int fontHegith)
{
	std::wstring path =	GET_SINGLE(ResourceManager)->GetResPath();
	path.append(L"Font\\");
	path.append(fontName.c_str());
	path.append(L".TTF");
	AddFontResource(path.c_str());
	pfont = CreateFont(fontHegith, fontWidth,
		0, 0, 0, 0, 0, 0, HANGEUL_CHARSET,
		0, 0, 0, VARIABLE_PITCH | FF_ROMAN, fontName.c_str());
}
