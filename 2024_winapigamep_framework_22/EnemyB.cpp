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
#include "Movement.h"

EnemyB::EnemyB()
{
}

EnemyB::~EnemyB()
{
}

float curRotation = 0;

void EnemyB::Update()
{
	if (prevShootTime + 0.1f < TIME)
	{
		
		Vec2 a{ 0,0 };
		
		prevShootTime = TIME;

		Vec2 attackDir = target->GetPos();
		attackDir -= GetPos();

		GetComponent<AttackCompo>()->TryFire(attackDir);
	}
}

void EnemyB::Render(HDC _hdc)
{
}
