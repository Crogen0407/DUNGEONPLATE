#include "pch.h"
#include "SpriteRenderer.h"
#include "Object.h"
#include "Texture.h"

SpriteRenderer::SpriteRenderer():
	texture(nullptr)
{
	brush = CreateSolidBrush(RGB(255, 0, 255));
}

SpriteRenderer::~SpriteRenderer()
{
	DeleteObject(memDC);
	DeleteObject(brush);
}

void SpriteRenderer::LateUpdate()
{
	if (texture == nullptr) return;
}

void SpriteRenderer::Render(HDC _hdc)
{
	if (texture == nullptr) return;
	Vec2 pos = GetOwner()->GetPos();
	Vec2 size = GetOwner()->GetSize();
	Vec2 texSize = { (float)texture->GetWidth(), (float)texture->GetHeight() };


	float sinA = sinf(angle-PI/2);
	float cosA = cosf(angle-PI/2);

	float halfWidth = GetOwner()->GetSize().x / 2;
	float halfHeight = GetOwner()->GetSize().y / 2;

	POINT vertices[4];

	vertices[0].x = (-halfWidth * cosA + (-halfHeight) * sinA);
	vertices[0].y = (-halfWidth * sinA - (-halfHeight) * cosA);

	vertices[1].x = (halfWidth * cosA + (-halfHeight) * sinA);
	vertices[1].y = (halfWidth * sinA - (-halfHeight) * cosA);

	vertices[2].x = (-halfWidth * cosA + (halfHeight)*sinA);
	vertices[2].y = (-halfWidth * sinA - (halfHeight)*cosA);

	vertices[3].x = (halfWidth * cosA + (halfHeight)*sinA);
	vertices[3].y = (halfWidth * sinA - (halfHeight)*cosA);

	float maxX = vertices[0].x;
	float maxY = vertices[0].y;
	float minX = vertices[0].x;
	float minY = vertices[0].y;

	for (int i = 1; i < 4; i++)
	{
		if (vertices[i].x > maxX)
			maxX = vertices[i].x;
		if (vertices[i].y > maxY)
			maxY = vertices[i].y;
		if (vertices[i].x < minX)
			minX = vertices[i].x;
		if (vertices[i].y < minY)
			minY = vertices[i].y;
	}

	hBmap = CreateCompatibleBitmap(texture->GetTexDC(), maxX - minX, maxY - minY);
	oldBitmap = (HBITMAP)SelectObject(memDC, hBmap);

	RECT rect = { 0, 0, maxX - minX, maxY - minY };
	FillRect(memDC, &rect, brush);
	POINT verticesSubset[3] = { vertices[0], vertices[1], vertices[2] };

	for (int i = 0; i < 4; ++i) {
		if (minX < 0)
		{
			vertices[i].x -= minX;
			if (vertices[i].x > maxX)
			{
				maxX = vertices[i].x;
			}
		}
		if (minY < 0)
		{
			vertices[i].y -= minY;
			if (vertices[i].y > maxY)
			{
				maxY = vertices[i].y;
			}
		}

		if (i != 3)
		{
			verticesSubset[i] = vertices[i];
		}
	}

	if (minX < 0)
		minX = 0;
	if (minY < 0)
		minY = 0;

	PlgBlt(memDC,
		verticesSubset,
		texture->GetTexDC(),
		0, 0,
		texture->GetWidth(),
		texture->GetHeight(),
		nullptr, 0, 0);

	float xPercent = (maxX - minX) / texSize.x;
	float yPercent = (maxY - minY) / texSize.y;
	size.x *= xPercent;
	size.y *= yPercent;
	TransparentBlt(_hdc,
		(int)((pos.x) - size.x / 2),
		(int)((pos.y) - size.y / 2),
		(int)size.x,
		(int)size.y,
		memDC,
		minX, minY, // ȸ�� ���� ���� �»��
		maxX - minX, // ȸ�� ���� ���� W
		maxY - minY, // ȸ�� ���� ���� H
		RGB(255, 0, 255)); // ��� ���� ����ȭ

	DeleteObject(hBmap);
	DeleteObject(oldBitmap);
}

void SpriteRenderer::SetTexture(std::wstring name, std::wstring path)
{
	texture = GET_SINGLE(ResourceManager)->TextureLoad(name, path);
	memDC = CreateCompatibleDC(texture->GetTexDC());
}

void SpriteRenderer::SetTexture(Texture* texture)
{
	this->texture = texture;
	memDC = CreateCompatibleDC(texture->GetTexDC());
}
