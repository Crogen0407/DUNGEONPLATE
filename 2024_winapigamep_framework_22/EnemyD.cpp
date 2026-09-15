#include "pch.h"
#include "EnemyD.h"
#include "Movement.h"
#include "HealthCompo.h"
#include "SpriteRenderer.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "ExplosionEffect.h"
#include "SceneManager.h"
#include "EventManager.h"
#include "TimeManager.h"
#include "Scene.h"
#include "Attacker.h"
#include "RoundAttackPattern.h"

EnemyD::EnemyD() : Enemy::Enemy()
{
	_giveExp = 3;
	_startTime = TIME;
	SetupSize({ 50,50 });
	_roundAttack = new RoundAttackPattern();
	_roundAttack->SetOwner(this);
	_target = FindObject(L"Player", LAYER::PLAYER);
	_texture = LOADTEXTURE(L"EnemyD", L"Texture\\Enemy04.png");

	AddComponent<Movement>();
	AddComponent<SpriteRenderer>();
	AddComponent<Attacker>();

	GetComponent<HealthCompo>()->SetOffsetY(60);
	GetComponent<HealthCompo>()->SetHp(10, 10);
	GetComponent<SpriteRenderer>()->SetTexture(_texture);
}

EnemyD::~EnemyD()
{
	delete _roundAttack;
}

void EnemyD::Update()
{
	Enemy::Update();

	if (_startTime + _lifeTime < TIME)
	{
		GetComponent<HealthCompo>()->ApplyDamage(9999);
	}

	float sizeDelta = 40 + (sinf(TIME * 50) * 0.5f + 0.5f) * 10;
	SetSize({ sizeDelta , sizeDelta });

	Vec2 dir = _target->GetPosition();
	dir -= GetPosition();
	float length = dir.Length();
	dir.Normalize();
	dir = dir * _moveSpeed * fDT;

	if (length < 100)
	{
		GetComponent<HealthCompo>()->ApplyDamage(9999);

		_target->GetComponent<HealthCompo>()->ApplyDamage(10);
	}

	GetComponent<Movement>()->Move(dir);
}

void EnemyD::OnDie()
{
	Enemy::OnDie();

	_roundAttack->Init(0, 20, 18);
	_roundAttack->UseSkill();
	_isDead = true;
}
