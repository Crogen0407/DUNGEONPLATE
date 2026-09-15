#include "pch.h"
#include "EnemyE.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "TimeManager.h"
#include "HealthCompo.h"
#include "Texture.h"
#include "Collider.h"
#include "Movement.h"
#include "Attacker.h"
#include "RoundAttackPattern.h"

EnemyE::EnemyE() : Enemy::Enemy()
{
	_giveExp = 3;
	SetupSize({ 50,50 });
	_prevAttack = TIME;
	_target = FindObject(L"Player", LAYER::PLAYER);
	_texture = LOADTEXTURE(L"Enemy5", L"Texture\\Enemy05.png");

	AddComponent<SpriteRenderer>();
	AddComponent<Movement>();
	AddComponent<Attacker>();

	GetComponent<HealthCompo>()->SetOffsetY(100);
	GetComponent<HealthCompo>()->SetHp(100, 100);
	GetComponent<SpriteRenderer>()->SetTexture(_texture);
	_roundAttack = new RoundAttackPattern();
	_roundAttack->SetOwner(this);
}

EnemyE::~EnemyE()
{
	delete _roundAttack;
}

void EnemyE::Update()
{
	Enemy::Update();

	_rotation += 360 * fDT;
	GetComponent<SpriteRenderer>()->SetAngle(_rotation, true);
	
	if (_prevAttack + _attackDelay < TIME)
	{
		_prevAttack = TIME;

		Vec2 dir = _target->GetPosition();
		dir -= GetPosition();
		dir.Normalize();

		GetComponent<Movement>()->Dash(dir, 500, 0.15f);
		_roundAttack->Init(15, 30, 12);
		_roundAttack->UseSkill();
	}
}
