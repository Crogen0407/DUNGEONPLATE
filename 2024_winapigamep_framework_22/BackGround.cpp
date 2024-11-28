#include "pch.h"
#include "BackGround.h"
#include "Collider.h"
#include "EventManager.h"
BackGround::BackGround()
{

}

BackGround::~BackGround()
{

}

void BackGround::Update()
{
	
}

void BackGround::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	RECT_RENDER(_hdc, vPos.x, vPos.y,
		vSize.x, vSize.y);
	ComponentRender(_hdc);
}
