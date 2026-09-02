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
#include "Animator.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "EventManager.h"

EnemyB::EnemyB() : Enemy::Enemy()
{
	_giveExp = 4;
	SetupSize({ 50,50 });
	_target = FindObject(L"Player", LAYER::PLAYER);
	texture = LOADTEXTURE(L"Enemy02", L"Texture\\Enemy02.png");
	Vec2 texSize = Vec2((int)texture->GetWidth() / 7, (int)texture->GetHeight());

	prevShootTime = TIME;
	AddComponent<Animator>();
	AddComponent<AttackCompo>();

	GetComponent<Animator>()
		->CreateAnimation(L"Enemy02Idle", texture, { 0.f, 0.f }, texSize, { (float)texSize.x, 0.f }, 7, 0.2f, false);
	GetComponent<Animator>()->PlayAnimation(L"Enemy02Idle", true, 100);

	GetComponent<HealthCompo>()->SetOffsetY(40);
	GetComponent<HealthCompo>()->SetHp(30,30);
}

EnemyB::~EnemyB()
{
}

float _rotation = 0;

void EnemyB::Update()
{
	Enemy::Update();

	float delay = shootDelay;

	if (prevShootTime + delay < TIME)
	{
		prevShootTime = TIME;

		for (int i = 0; i < 4; i++)
		{
			Vec2 attackDir = { sin(_rotation * Deg2Rad), cos(_rotation * Deg2Rad) };
			GetComponent<AttackCompo>()->TryFireBullet(attackDir, 500);

			_rotation += 90;
		}

		_rotation += 45;
	}
}