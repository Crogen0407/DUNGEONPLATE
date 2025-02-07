#include "pch.h"
#include "EnemyA.h"
#include "Enemy.h"
#include "Scene.h"
#include "Player.h"
#include "Object.h"
#include "Texture.h"
#include "Projectile.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "AttackCompo.h"
#include "Movement.h"
#include "GuidedMissile.h"
#include "SpriteRenderer.h"
#include "Animator.h"
#include "Animation.h"
#include "HealthCompo.h"
#include "EventManager.h"

EnemyA::EnemyA() : Enemy::Enemy()
{
	_giveExp = 3;
	_target = FindObject(L"Player", LAYER::PLAYER);
	SetSize({ 50, 50 });

	_prevShootTime = TIME;
	Texture* texture = LOADTEXTURE(L"Enemy01", L"Texture\\Enemy01.bmp");
	Vec2 texSize = Vec2((int)texture->GetWidth() / 3, (int)texture->GetHeight());

	//AddComponent<HealthCompo>();
	AddComponent<Animator>();
	AddComponent<AttackCompo>();
	AddComponent<Movement>();

	GetComponent<Animator>()
		->CreateAnimation(L"Enemy01Idle", texture, { 0,0 }, texSize, { (int)texSize.x, 0 }, 3, 0.2f);
	GetComponent<Animator>()->PlayAnimation(L"Enemy01Idle", true, 5);
	GetComponent<HealthCompo>()->SetOffsetY(42);
	GetComponent<HealthCompo>()->SetHp(20,20);
}

EnemyA::~EnemyA()
{
}

void EnemyA::Update()
{
	if (_prevShootTime + _shootDelay < TIME)
	{
		Vec2 dir = _target->GetPos();
		dir -= GetPos();

		_prevShootTime = TIME;
		GetComponent<AttackCompo>()->TryFireBullet(dir, 500);
	}

	if (_prevDash + 2 < TIME)
	{
		_prevDash = TIME;

		Vec2 dashDir = { rand() % 2 == 0 ? 1 : -1, 0 };
		if (GetPos().x < 100) dashDir = { 1,0 };
		else if (GetPos().x > SCREEN_WIDTH - 100) dashDir = { -1,0 };

		GetComponent<Movement>()->Dash(dashDir, 1000.f, 0.1f);
	}
}

void EnemyA::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}
