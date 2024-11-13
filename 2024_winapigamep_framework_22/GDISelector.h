#pragma once
class GDISelector
{
public:
	GDISelector(HDC _hdc, PEN_TYPE _ePen);
	GDISelector(HDC _hdc, BRUSH_TYPE _eBrush);
	GDISelector(HDC _hdc, HFONT _font);
	~GDISelector();
private:
	HDC		m_hDC;
	HPEN	m_hDefaultPen;
	HBRUSH	m_hDefaultBrush;
	HFONT   m_hDefaultFont;
	HFONT	m_hFont;
};
