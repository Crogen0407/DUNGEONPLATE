#include "pch.h"
#include "Slider.h"
#include "Canvas.h"
#include "Texture.h"
#include "Core.h"

Slider::Slider()
{
	GET_SINGLE(Core)->GetRenderTarget()->CreateSolidColorBrush(D2D1::ColorF(0x0f380f), _backBrush.GetAddressOf());
	GET_SINGLE(Core)->GetRenderTarget()->CreateSolidColorBrush(D2D1::ColorF(0x8bac0f), _fillBrush.GetAddressOf());
}

Slider::~Slider()
{
}

void Slider::LateUpdate()
{
}

void Slider::Render(ComPtr<ID2D1RenderTarget> renderTarget)
{
	if (_owner == nullptr) return;
	Vec2 pos = GetPosition() + _owner->GetPosition();
	if (_parent != nullptr)
		pos += _parent->GetPosition();

	Vec2 size = GetSize();

	renderTarget->FillRectangle(D2D1::RectF(
		pos.x - size.x / 2,
		pos.y - size.y / 2,
		pos.x + size.x / 2,
		pos.y + size.y / 2),
		_backBrush.Get());

	if (isVertical)
	{
		valueVec.x = 1;
		valueVec.y = value * 2 - 1;
	}
	else
	{
		valueVec.x = value * 2 - 1;
		valueVec.y = 1;
	}

	if (flip)
	{
		renderTarget->FillRectangle(D2D1::RectF(
			pos.x - (size.x * valueVec.x) / 2 + offsetX / 2,
			pos.y - (size.y * valueVec.y) / 2 + offsetY / 2,
			pos.x + (size.x / 2) - offsetX / 2,
			pos.y + (size.y / 2) - offsetY / 2),
			_fillBrush.Get());
	}
	else
	{
		renderTarget->FillRectangle(D2D1::RectF(
			pos.x - (size.x / 2) + offsetX / 2,
			pos.y - (size.y / 2) + offsetY / 2,
			pos.x + (size.x * valueVec.x) / 2 - offsetX / 2,
			pos.y + (size.y * valueVec.y) / 2 - offsetY / 2),
			_fillBrush.Get());
	}
}
