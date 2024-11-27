#include "pch.h"
#include "Slider.h"
#include "Object.h"
#include "Texture.h"

Slider::Slider():
	backTexture(nullptr),
	fillTexture(nullptr)
{
	value = 1.f;
}

Slider::~Slider()
{
}

void Slider::LateUpdate()
{
}

void Slider::Render(HDC _hdc)
{
	Vec2 pos = GetPos();
	Vec2 size = GetSize();

	if (backTexture != nullptr)
	{
		//BackTexture
		TransparentBlt(_hdc,
			(int)(pos.x) - size.x / 2,
			(int)(pos.y) - size.y / 2,
			(int)size.x,
			(int)size.y,
			backTexture->GetTexDC(),
			0,
			0,
			backTexture->GetWidth(),
			backTexture->GetHeight(),
			RGB(255, 0, 255));
	}

	if (fillTexture == nullptr) return;

	Vec2 fillPos = { (pos.x) - size.x / 2 + offsetX / 2, (pos.y) - size.y / 2 + offsetY / 2 };;
	Vec2 fillSize;
	Vec2 maxFillSize = { size.x - offsetX, size.y - offsetY };

	if (isVertical) fillSize = { size.x - offsetX, size.y - (size.y * (1 - value)) - offsetY };
	else fillSize = { size.x - (size.x * (1 - value)) - offsetX, size.y - offsetY };

	if (flip)
	{
		if (isVertical)
		{
			fillPos = { fillPos.x, fillPos.y + (maxFillSize.y - fillSize.y)};
		}
		else
		{
			fillPos = { fillPos.x + (maxFillSize.x - fillSize.x), fillPos.y};
		}
	}

	//FillTexture
	TransparentBlt(_hdc,
		(int)fillPos.x,
		(int)fillPos.y,
		(int)fillSize.x,
		(int)fillSize.y,
		fillTexture->GetTexDC(),
		0, 0,
		fillTexture->GetWidth(),
		fillTexture->GetHeight(),
		RGB(255, 0, 255));
}
