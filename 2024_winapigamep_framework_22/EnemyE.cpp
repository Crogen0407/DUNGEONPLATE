#include "pch.h"
#include "EnemyE.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "TimeManager.h"
#include "HealthCompo.h"
#include "Texture.h"
#include "Collider.h"
#include "Movement.h"
#include "AttackCompo.h"
#include "Texture.h"
#include "RoundAttackPattern.h"

EnemyE::EnemyE()
{
	_giveExp = 3;
	SetSize({ 50,50 });
	_prevAttack = TIME;
	_target = FindObject(L"Player", LAYER::PLAYER);
	_texture = LOADTEXTURE(L"Enemy5", L"Texture\\Enemy05.bmp");

	AddComponent<SpriteRenderer>();
	AddComponent<Movement>();
	AddComponent<AttackCompo>();

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
	_rotation += 360 * fDT;
	_rotation = (int)_rotation % 360;
	Vec2 rot = { cos(_rotation * Deg2Rad), sin(_rotation * Deg2Rad) };
	GetComponent<SpriteRenderer>()->LookAt(rot);

	if (_prevAttack + _attackDelay < TIME)
	{
		_prevAttack = TIME;

		Vec2 dir = _target->GetPos();
		dir -= GetPos();
		dir.Normalize();

		GetComponent<Movement>()->Dash(dir, 500, 0.15f);
		_roundAttack->Init(15, 30, 12);
		_roundAttack->UseSkill();
	}
}

void EnemyE::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}
