#include "pch.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "Texture.h"
#include<algorithm>

SpriteRenderer::SpriteRenderer():
	texture(nullptr)
{
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::LateUpdate()
{
	if (texture == nullptr) return;
}

void SpriteRenderer::Render(ComPtr<ID2D1RenderTarget> renderTarget)
{
	if (texture == nullptr) return;
	if (enable == false) return;
	Vec2 pos = GetOwner()->GetPosition();
	Vec2 size = GetOwner()->GetSize();
	Vec2 texSize = { (float)texture->GetWidth(), (float)texture->GetHeight() };

	D2D1_MATRIX_3X2_F transformMatrix = 
		D2D1::Matrix3x2F::Rotation(
			angle, D2D1::Point2F(pos.x, pos.y)
		);
	renderTarget->SetTransform(transformMatrix);
	{
		renderTarget->DrawBitmap(
			texture->GetBitmap().Get(),
			D2D1::RectF(
				pos.x - size.x / 2,
				pos.y - size.y / 2,
				pos.x + size.x / 2,
				pos.y + size.y / 2), 
			1.f, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR
		);
	}
	renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
}

void SpriteRenderer::SetTexture(std::wstring name, std::wstring path)
{
	texture = LOADTEXTURE(name, path);
}

void SpriteRenderer::SetTexture(Texture* texture)
{
	this->texture = texture;
}
