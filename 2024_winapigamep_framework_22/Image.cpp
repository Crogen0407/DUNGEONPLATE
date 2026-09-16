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

void Image::Render(ComPtr<ID2D1RenderTarget> renderTarget)
{
	if (texture == nullptr) return;

	if (_owner == nullptr) return;
	Vec2 pos = GetPosition() + _owner->GetPosition();
	if (_parent != nullptr)
		pos += _parent->GetPosition();

	Vec2 size = GetSize();

	D2D1_RECT_F destRect = D2D1::RectF(
			pos.x - size.x / 2,
			pos.y - size.y / 2,
			pos.x + size.x / 2,
			pos.y + size.y / 2
		);

	// 9-slice를 사용하지 않는다면 그냥 바로 렌더링을 한다.
	if (useNineSlice == false)
	{
		renderTarget->DrawBitmap(
			texture->GetBitmap().Get(),
			destRect,
			1.f,
			D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR
		);
		return;
	}

	Vec2 textureSize = { (float)texture->GetWidth(), (float)texture->GetHeight() };

	D2D1_RECT_F srcRects[9] = 
	{
		{ 0, 0, borderSize, borderSize }, // TL
		{ borderSize, 0, textureSize.x - borderSize, borderSize }, // T
		{ textureSize.x - borderSize, 0, textureSize.x, borderSize }, // TR

		{ 0, borderSize, borderSize, textureSize.y - borderSize }, // L
		{ borderSize, borderSize, textureSize.x - borderSize, textureSize.y - borderSize}, // C
		{ textureSize.x - borderSize, borderSize, textureSize.x, textureSize.y - borderSize }, // R

		{ 0, textureSize.y - borderSize, borderSize, textureSize.y }, // BL
		{ borderSize, textureSize.y - borderSize, textureSize.x - borderSize, textureSize.y }, // B
		{ textureSize.x - borderSize, textureSize.y - borderSize, textureSize.x, textureSize.y }, // BR
	};

	float destBorderSize = multiplier * borderSize;

	D2D1_RECT_F destRects[9] = {
		{ destRect.left, destRect.top, destRect.left + destBorderSize, destRect.top + destBorderSize },  // TL
		{ destRect.left + destBorderSize -1, destRect.top, destRect.right - destBorderSize + 1, destRect.top + destBorderSize },  // T
		{ destRect.right - destBorderSize, destRect.top, destRect.right, destRect.top + destBorderSize }, // TR

		{ destRect.left, destRect.top + destBorderSize - 1, destRect.left + destBorderSize, destRect.bottom - destBorderSize + 1 }, // L
		{ destRect.left + destBorderSize - 1, destRect.top + destBorderSize - 1, destRect.right - destBorderSize + 1, destRect.bottom - destBorderSize + 1}, // C (*늘어남)
		{ destRect.right - destBorderSize, destRect.top + destBorderSize - 1, destRect.right, destRect.bottom - destBorderSize + 1 }, // R

		{ destRect.left, destRect.bottom - destBorderSize, destRect.left + destBorderSize, destRect.bottom },  // BL
		{ destRect.left + destBorderSize - 1, destRect.bottom - destBorderSize, destRect.right - destBorderSize + 1, destRect.bottom },  // B
		{ destRect.right - destBorderSize, destRect.bottom - destBorderSize, destRect.right, destRect.bottom } // BR
	};

	for (int i = 0; i < 9; i++){
		renderTarget->DrawBitmap(
			texture->GetBitmap().Get(),
			destRects[i],
			1.f,
			D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
			srcRects[i]);
	}
}