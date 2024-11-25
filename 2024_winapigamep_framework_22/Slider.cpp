#include "pch.h"
#include "Slider.h"
#include "Object.h"
#include "Texture.h"

Slider::Slider():
	backTexture(nullptr),
	fillTexture(nullptr)
{
}

Slider::~Slider()
{
}

void Slider::LateUpdate()
{
}

void Slider::Render(HDC _hdc)
{
	if (backTexture == nullptr) return;

	Vec2 pos = GetOwner()->GetPos();
	Vec2 size = GetOwner()->GetSize();

	//BackTexture
	TransparentBlt(_hdc,
		(int)(pos.x) - size.x / 2,
		(int)(pos.y) - size.y / 2,
		(int)(pos.x) + size.x / 2,
		(int)(pos.y) + size.y / 2,
		backTexture->GetTexDC(),
		0,
		0,
		backTexture->GetWidth(),
		backTexture->GetHeight(),
		RGB(255, 0, 255));

	//FillTexture
	TransparentBlt(_hdc,
		(int)(pos.x) - size.x / 2 + offsetX,
		(int)(pos.y) - size.y / 2 + offsetY,
		(int)(pos.x) + size.x / 2 - offsetX,
		(int)(pos.y) + size.y / 2 - offsetY,
		fillTexture->GetTexDC(),
		0,
		0,
		fillTexture->GetWidth(),
		fillTexture->GetHeight(),
		RGB(255, 0, 255));
}
