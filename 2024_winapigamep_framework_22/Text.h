#pragma once
#include "UI.h"
class Text : public UI
{
public:
	Text();
	~Text() override;
public:
	void LateUpdate() override;
	void Render(HDC _hdc) override;
public:
	void LoadFont(std::wstring fontName, int fontWidth, int fontHegith);
public:
	void SetPitchAndFamily(DWORD iPitchAndFamily)
	{
		this->iPitchAndFamily = iPitchAndFamily;
	}
	void SetText(wstring str)
	{
		text = str;
	}
	const wstring& GetText()
	{
		return text;
	}
	void SetColor(COLORREF color)
	{
		this->color = color;
	}
private:
	DWORD iPitchAndFamily;
	HFONT pfont;
	wstring text;
	COLORREF color;
};

