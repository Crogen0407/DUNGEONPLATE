#pragma once
#include "UI.h"
class Texture;
class Slider : public UI
{
public:
	Slider();
	~Slider() override;
public:
	void LateUpdate() override;
	void Render(HDC _hdc) override;
public:
	void SetValue(float value)
	{
		this->value = value;
	}
public:
	float value = 1.f;
	Vec2 valueVec = Vec2(1.f, 1.f);
	bool isVertical = false;
	bool flip = false;
	int offsetX = 5;
	int offsetY = 5;
	HBRUSH backBrush;
	HBRUSH fillBrush;
public:
	COLORREF backColor;
	COLORREF fillColor;
};