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

EnemyE::EnemyE()
{
	SetSize({ 50,50 });
	_prevAttack = TIME;
	_target = FindObject(L"Player", LAYER::PLAYER);
	_texture = LOADTEXTURE(L"Enemy5", L"Texture\\Enemy05.bmp");

	AddComponent<SpriteRenderer>();
	AddComponent<Movement>();

	GetComponent<HealthCompo>()->SetOffsetY(100);
	GetComponent<HealthCompo>()->SetHp(1000, 1000);
	GetComponent<SpriteRenderer>()->SetTexture(_texture);
}

EnemyE::~EnemyE()
{
}

void EnemyE::Update()
{
	if (_prevAttack + _attackDelay < TIME)
	{
		_prevAttack = TIME;

		Vec2 dir = _target->GetPos();
		dir -= GetPos();
		dir.Normalize();

		GetComponent<Movement>()->Dash(dir, 1000, 0.2f);
	}
}

void EnemyE::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void EnemyE::EnterCollision(Collider* _other)
{
	
}
