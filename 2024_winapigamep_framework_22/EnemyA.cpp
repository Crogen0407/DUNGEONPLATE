#include "pch.h"
#include "EnemyA.h"
#include "Enemy.h"
#include "Scene.h"
#include "Player.h"
#include "Projectile.h"
#include "SceneManager.h"
#include "TimeManager.h"

EnemyA::EnemyA()
{
	player = FindObject(L"Player", LAYER::PLAYER);
}

EnemyA::~EnemyA()
{
}

void EnemyA::Update()
{
	if (prevShootTime + shootDelay < TIME)
	{
		Fire();
		return;
	}


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

void EnemyA::Fire()
{
	prevShootTime = TIME;

	Vec2 dir = player->GetPos();
	dir -= GetPos();

	Projectile* projectile = new Projectile();
	projectile->SetPos(GetPos());
	projectile->SetSize({ 10, 10 });

	GET_SINGLE(SceneManager)->GetCurrentScene()
		->AddObject(projectile, LAYER::PROJECTILE);

	projectile->SetDir(dir);
}
