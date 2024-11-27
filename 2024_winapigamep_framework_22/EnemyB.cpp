#include "pch.h"
#include "EnemyB.h"
#include "Enemy.h"
#include "Scene.h"
#include "Player.h"
#include "Object.h"
#include "Projectile.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "AttackCompo.h"
#include "HealthCompo.h"
#include "Movement.h"

EnemyB::EnemyB()
{
	target = FindObject(L"Player", LAYER::PLAYER);

	AddComponent<AttackCompo>();
	AddComponent<HealthCompo>();
}

EnemyB::~EnemyB()
{
}

int curShoot = 0;

void EnemyB::Update()
{
	float delay = 0.1f;
	

	if (curShoot % 3 == 0) delay = shootDelay;

	if (prevShootTime + delay < TIME)
	{
		//cout << delay << " ";
		prevShootTime = TIME;

		Vec2 attackDir = target->GetPos();
		attackDir -= GetPos();

		GetComponent<AttackCompo>()->TryFire(attackDir);
		curShoot++;
	}
}

void EnemyB::Render(HDC _hdc)
{
	HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH oldbrush = (HBRUSH)SelectObject(_hdc, brush);

	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	RECT_RENDER(_hdc, vPos.x, vPos.y, vSize.x, vSize.y);

	SelectObject(_hdc, oldbrush);
	DeleteObject(brush);
}
