#pragma once
#include "Component.h"
class Texture;
class Image : public Component
{
public:
	Image();
	~Image() override;
public:
	Texture* texture;
public:
	void LateUpdate() override;
	void Render(HDC _hdc) override;
};

