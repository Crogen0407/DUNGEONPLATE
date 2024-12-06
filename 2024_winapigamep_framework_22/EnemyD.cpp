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
#include "AttackCompo.h"
#include "RoundAttackSkill.h"

EnemyD::EnemyD()
{
	_startTime = TIME;
	SetSize({ 50,50 });
	_roundAttack = new RoundAttackSkill();
	_roundAttack->SetOwner(this);
	_target = FindObject(L"Player", LAYER::PLAYER);
	_texture = LOADTEXTURE(L"EnemyD", L"Texture\\Enemy04.bmp");

	AddComponent<Movement>();
	AddComponent<HealthCompo>();
	AddComponent<SpriteRenderer>();
	AddComponent<AttackCompo>();

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
	if (_startTime + _lifeTime < TIME)
	{
		OnDie();
	}

	Vec2 dir = _target->GetPos();
	dir -= GetPos();
	float length = dir.Length();
	dir.Normalize();
	dir = dir * _moveSpeed * fDT;

	if (length < 100)
	{
		OnDie();

		_target->GetComponent<HealthCompo>()->ApplyDamage(10);
	}

	GetComponent<Movement>()->Move(dir);
}

void EnemyD::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void EnemyD::OnDie()
{
	Enemy::OnDie();

	_roundAttack->Init(0, 20, 18);
	_roundAttack->UseSkill();
	_isDead = true;
}
