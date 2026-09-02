#pragma once
#include "UI.h"
class Texture;
class Image : public UI
{
public:
	Image();
	~Image() override;

public:
	Texture* texture;
	bool useNineSlice = true;
	float borderSize = 5.f;
	float multiplier = 4.f;

public:
	void LateUpdate() override;
	void Render(ComPtr<ID2D1RenderTarget> renderTarget) override;
};

