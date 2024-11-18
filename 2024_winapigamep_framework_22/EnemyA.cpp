#include "pch.h"
#include "EnemyA.h"
#include "Enemy.h"
#include "SceneManager.h"

EnemyA::EnemyA()
{
}

EnemyA::~EnemyA()
{
}

void EnemyA::Update()
{
	//Object* player = ;
}

void EnemyA::Render(HDC _hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldbrush = (HBRUSH)SelectObject(_hdc, brush);

	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	RECT_RENDER(_hdc, vPos.x, vPos.y, vSize.x, vSize.y);

	SelectObject(_hdc, oldbrush); 
	DeleteObject(brush);
}
