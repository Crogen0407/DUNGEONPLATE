#pragma once
#include "UI.h"
class Text : public UI
{
public:
	Text();
	~Text() override;

public:
	void LateUpdate() override;
	void Render(ComPtr<ID2D1RenderTarget> renderTarget) override;

public:
	void LoadFont(std::wstring fontName, float fontSize);

public:
	void SetPitchAndFamily(DWRITE_TEXT_ALIGNMENT alignment = DWRITE_TEXT_ALIGNMENT_LEADING, DWRITE_PARAGRAPH_ALIGNMENT paragraphAlignment = DWRITE_PARAGRAPH_ALIGNMENT_CENTER)
	{
		_textFormat->SetTextAlignment(alignment);
		_textFormat->SetParagraphAlignment(paragraphAlignment);
	}
	void SetText(wstring str)
	{
		_text = str;
	}
	const wstring& GetText()
	{
		return _text;
	}
	void SetColor(D2D1::ColorF color);
	void SetStyle(DWRITE_FONT_STYLE style = DWRITE_FONT_STYLE_NORMAL)
	{
		_style = style;
	}
	void SetWeight(DWRITE_FONT_WEIGHT weight = DWRITE_FONT_WEIGHT_NORMAL)
	{
		_weight = weight;
	}
	void SetStretch(DWRITE_FONT_STRETCH stretch = DWRITE_FONT_STRETCH_NORMAL)
	{
		_stretch = stretch;
	}

private:
	wstring _text;
	D2D1_COLOR_F _color;
	DWRITE_FONT_STYLE _style;
	DWRITE_FONT_WEIGHT _weight;
	DWRITE_FONT_STRETCH _stretch;

	ComPtr<IDWriteTextFormat> _textFormat;
	ComPtr<ID2D1SolidColorBrush> _brush;
};

