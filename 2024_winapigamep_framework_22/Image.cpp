#include "pch.h"
#include "Image.h"
#include "Canvas.h"
#include "Texture.h"

Image::Image() :
	texture(nullptr)
{
}

Image::~Image()
{
}

void Image::LateUpdate()
{
}

void Image::Render(HDC _hdc)
{
	if (texture == nullptr) return;

	Vec2 pos = GetPos() + owner->GetPos();
	Vec2 size = GetSize();

	TransparentBlt(_hdc,
		(int)(pos.x) - size.x / 2,
		(int)(pos.y) - size.y / 2,
		(int)size.x,
		(int)size.y,
		texture->GetTexDC(),
		0,
		0,
		texture->GetWidth(),
		texture->GetHeight(),
		RGB(255, 0, 255));
}