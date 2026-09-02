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
	void Render(ComPtr<ID2D1RenderTarget> renderTarget) override;

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

public:
	ComPtr<ID2D1SolidColorBrush> _fillBrush;
	ComPtr<ID2D1SolidColorBrush> _backBrush;
};