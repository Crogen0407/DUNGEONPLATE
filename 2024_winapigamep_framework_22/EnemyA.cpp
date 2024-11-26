#include "pch.h"
#include "EnemyA.h"
#include "Enemy.h"
#include "Scene.h"
#include "Player.h"
#include "Object.h"
#include "Projectile.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "AttackCompo.h"
#include "Movement.h"

EnemyA::EnemyA()
{
	m_moveDesire = Vec2(0, 0);
	target = FindObject(L"Player", LAYER::PLAYER);

	AddComponent<AttackCompo>();
	AddComponent<Movement>();
}

EnemyA::~EnemyA()
{
}

void EnemyA::Update()
{
	if (prevShootTime + shootDelay < TIME)
	{
		prevShootTime = TIME;

		Vec2 attackDir = target->GetPos();
		attackDir -= GetPos();

		GetComponent<AttackCompo>()->TryFire(attackDir);
	}


	if (prevDash + 2 < TIME)
	{
		prevDash = TIME;

		Vec2 dashDir = { rand() % 2 == 0 ? 1 : -1, 0 };
		if (GetPos().x < 100) dashDir = { 1,0 };
		else if (GetPos().x > SCREEN_WIDTH - 100) dashDir = { -1,0 };

		GetComponent<Movement>()->Dash(dashDir, 1000.f, 0.1f);
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

//void EnemyA::Fire()
//{
//	prevShootTime = TIME;
//
//	Vec2 dir = player->GetPos();
//	dir -= GetPos();
//
//	Projectile* projectile = new Projectile();
//	projectile->SetPos(GetPos());
//	projectile->SetSize({ 10, 10 });
//
//	GET_SINGLE(SceneManager)->GetCurrentScene()
//		->AddObject(projectile, LAYER::PROJECTILE);
//
//	projectile->SetDir(dir);
//}
