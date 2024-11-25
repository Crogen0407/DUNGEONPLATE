#include "pch.h"
#include "Image.h"
#include "Object.h"
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

	Vec2 pos = GetOwner()->GetPos();
	Vec2 size = GetOwner()->GetSize();

	TransparentBlt(_hdc,
		(int)(pos.x) - size.x / 2,
		(int)(pos.y) - size.y / 2,
		(int)(pos.x) + size.x / 2,
		(int)(pos.y) + size.y / 2,
		texture->GetTexDC(),
		0,
		0,
		texture->GetWidth(),
		texture->GetHeight(),
		RGB(255, 0, 255));
}