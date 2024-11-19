#include "pch.h"
#include "AttackDirArrow.h"
#include "GDISelector.h"
#include "Object.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "SpriteRenderer.h"
AttackDirArrow::AttackDirArrow()
	: parent(nullptr),
	m_defaultTex(nullptr),
	spriteRenderer(nullptr)
{
	m_defaultTex = GET_SINGLE(ResourceManager)->TextureLoad(L"dirArrow", L"Texture\\arrow.bmp");
	AddComponent<SpriteRenderer>();
	spriteRenderer = GetComponent<SpriteRenderer>();
	spriteRenderer->SetTexture(L"arrow", L"Texture/arrow.bmp");
	spriteRenderer->SetAngle(PI);
}

AttackDirArrow::~AttackDirArrow()
{
}

void AttackDirArrow::SetParent(Object* parent)
{
	this->parent = parent;
}

void AttackDirArrow::Update()
{
	if (parent == nullptr) return;

	Vec2 mousePos = GET_MOUSEPOS;
	dir = mousePos - parent->GetPos();
	dir.Normalize();

	float distance = 30;

	Vec2 selfPos = (dir * distance) + parent->GetPos();

	float angle = atan2(dir.y, dir.x);

	spriteRenderer->SetAngle(angle, false);
	//spriteRenderer->LookAt(dir);
	SetPos(selfPos);
}

void AttackDirArrow::Render(HDC _hdc)
{
	ComponentRender(_hdc);
	//if (m_defaultTex == nullptr) return;
	//Vec2 pos = GetPos();
	//Vec2 size = GetSize();
	//Vec2 texSize = { (float)m_defaultTex->GetWidth(), (float)m_defaultTex->GetHeight() };
	////GDISelector gdi = GDISelector(_hdc, BRUSH_TYPE::RED);
	////GDISelector gdi2 = GDISelector(_hdc, PEN_TYPE::RED);
	////::ELLIPSE_RENDER(_hdc, GetPos().x, GetPos().y, 15, 15);
	//
	//double angle = atan2(dir.y, dir.x);
	//angle -= PI/2;
	//SetAngle(angle);

	//float sinA = sinf(GetAngle());
	//float cosA = cosf(GetAngle());

	//float halfWidth = GetSize().x / 2;
	//float halfHeight = GetSize().y / 2;

	//POINT vertices[4];

	//vertices[0].x = (-halfWidth * cosA + (-halfHeight) * sinA);
	//vertices[0].y = (-halfWidth * sinA - (-halfHeight) * cosA);

	//vertices[1].x = (halfWidth * cosA + (-halfHeight) * sinA);
	//vertices[1].y = (halfWidth * sinA - (-halfHeight) * cosA);

	//vertices[2].x = (-halfWidth * cosA + (halfHeight)*sinA);
	//vertices[2].y = (-halfWidth * sinA - (halfHeight)*cosA);
	//				
	//vertices[3].x = (halfWidth * cosA + (halfHeight)*sinA);
	//vertices[3].y = (halfWidth * sinA - (halfHeight)*cosA);

	//float maxX = vertices[0].x;
	//float maxY = vertices[0].y;
	//float minX = vertices[0].x;
	//float minY = vertices[0].y;

	//for (int i = 0; i < 4; i++)
	//{
	//	if (vertices[i].x > maxX)
	//		maxX = vertices[i].x;
	//	if (vertices[i].y > maxY)
	//		maxY = vertices[i].y;
	//	if (vertices[i].x < minX)
	//		minX = vertices[i].x;
	//	if (vertices[i].y < minY)
	//		minY = vertices[i].y;
	//}

	//HDC memDC = CreateCompatibleDC(m_defaultTex->GetTexDC());
	//HBITMAP hBmap = CreateCompatibleBitmap(m_defaultTex->GetTexDC(), maxX - minX, maxY - minY);
	//HBITMAP oldBitmap = (HBITMAP)SelectObject(memDC, hBmap);

	//RECT rect = { 0, 0, maxX - minX, maxY - minY };
	//HBRUSH brush = CreateSolidBrush(RGB(255, 0, 255));
	//FillRect(memDC, &rect, brush);

	//POINT verticesSubset[3] = { vertices[0], vertices[1], vertices[2] };

	//for (int i = 0; i < 4; ++i) {
	//	if (minX < 0)
	//	{
	//		vertices[i].x -= minX;
	//		if (vertices[i].x > maxX)
	//		{
	//			maxX = vertices[i].x;
	//		}
	//	}
	//	if (minY < 0)
	//	{
	//		vertices[i].y -= minY;
	//		if (vertices[i].y > maxY)
	//		{
	//			maxY = vertices[i].y;
	//		}
	//	}


	//	if (i != 3)
	//	{
	//		verticesSubset[i] = vertices[i];
	//	}
	//}

	//if (minX < 0)
	//	minX = 0;
	//if (minY < 0)
	//	minY = 0;

	//PlgBlt(memDC,
	//	verticesSubset,
	//	m_defaultTex->GetTexDC(),
	//	0, 0, 
	//	m_defaultTex->GetWidth(), 
	//	m_defaultTex->GetHeight(), 
	//	nullptr, 0, 0);

	////::BitBlt(_hdc,
	////	(int)(pos.x) - size.x / 2,
	////	(int)(pos.y) - size.y / 2,
	////	(int)size.x,
	////	(int)size.y,
	////	memDC,
	////	minX, minY, SRCCOPY);

	//TransparentBlt(_hdc,
	//(int)(pos.x) - size.x / 2,
	//(int)(pos.y) - size.y / 2,
	//(int)size.x,
	//(int)size.y,
	//memDC,
	//minX, minY, // 회전 이후 영역 좌상단
	//maxX - minX, // 회전 이후 영역 W
	//maxY - minY, // 회전 이후 영역 H
	//RGB(255, 0, 255)); // 흰색 영역 투명화

	//DeleteObject(memDC);
	//DeleteObject(hBmap);
	//DeleteObject(oldBitmap);
	//DeleteObject(brush);
}
