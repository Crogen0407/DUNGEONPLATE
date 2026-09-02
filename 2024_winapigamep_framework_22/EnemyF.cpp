#include "pch.h"
#include "EnemyF.h"
#include "TimeManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "Animator.h"
#include "AttackCompo.h"
#include "Movement.h"
#include "HealthCompo.h"

EnemyF::EnemyF()
{
	_giveExp = 5;
	_target = FindObject(L"Player", LAYER::PLAYER);
	SetupSize({ 70, 70 });

	_prevShootTime = TIME;
	Texture* texture = LOADTEXTURE(L"Enemy07", L"Texture\\Enemy07.png");
	Vec2 texSize = Vec2((float)texture->GetWidth()/2.f, (float)texture->GetHeight());

	AddComponent<Animator>();
	AddComponent<AttackCompo>();
	AddComponent<Movement>();

	GetComponent<Animator>()
		->CreateAnimation(L"Enemy07Idle", texture, { 0.f, 0.f }, texSize, { texSize.x, 0 }, 2, 0.2f);
	GetComponent<Animator>()->PlayAnimation(L"Enemy07Idle", true, 5);
	GetComponent<HealthCompo>()->SetOffsetY(42);
	GetComponent<HealthCompo>()->SetHp(100, 100);
}

EnemyF::~EnemyF()
{
}

void EnemyF::Update()
{
	Enemy::Update();
	if (_prevMoveTime + _moveDelay < TIME)
	{
		OnMove();
		_prevMoveTime = TIME;
	}

	if (_prevShootTime + _shootDelay < TIME)
	{
		OnShoot();
		_prevShootTime = TIME;
	}
}

void EnemyF::OnMove()
{
	float angle = rand();
	Vec2 dir = XMFLOAT2(cosf(angle), sinf(angle));
	GetComponent<Movement>()->Dash(dir, 300, 0.5f);
}

void EnemyF::OnShoot()
{
	Vec2 dir = _target->GetPosition();
	dir -= GetPosition();
	float rotation = atan2(dir.y, dir.x) * Rad2Deg;
	Vec2 dir1 = { cos((rotation - 30) * Deg2Rad) , sin((rotation - 30) * Deg2Rad) };
	Vec2 dir2 = { cos((rotation + 30) * Deg2Rad), sin((rotation + 30) * Deg2Rad) };

	GetComponent<AttackCompo>()->TryFireBullet(dir, 500);
	GetComponent<AttackCompo>()->TryFireBounceBullet(dir1);
	GetComponent<AttackCompo>()->TryFireBounceBullet(dir2);
}
