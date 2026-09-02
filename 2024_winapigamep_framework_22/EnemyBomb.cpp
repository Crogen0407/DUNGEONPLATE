#include "pch.h"
#include "EnemyBomb.h"
#include "TimeManager.h"
#include "Collider.h"
#include "SpriteRenderer.h"
#include "PoolManager.h"

EnemyBomb::EnemyBomb()
{
	_poolName = L"EnemyBomb";
	_speed = 300.f;
	_damage = 20.f;
	_texture = LOADTEXTURE(L"EnemyBomb", L"Texture\\EnemyBomb.png");
	_parriedTexture = LOADTEXTURE(L"EnemyBomb_R", L"Texture\\EnemyBomb_R.png");

	SetSize({ 50, 50 });
	AddComponent<Collider>();
	AddComponent<SpriteRenderer>();

	GetComponent<Collider>()->SetSize(GetSize());
	GetComponent<SpriteRenderer>()->SetTexture(_texture);
}

EnemyBomb::~EnemyBomb()
{
}

void EnemyBomb::Update()
{
	AddPosition(_dir * _speed * fDT);

	Vec2 pos = GetPosition();

	if (pos.y < -pos.y / 2 || pos.x < -pos.x / 2
		|| pos.y > SCREEN_HEIGHT + pos.y || pos.x > SCREEN_WIDTH)
	{
		PUSH(_poolName, this);
	}
}

void EnemyBomb::Parry()
{
	_damage = 10.f;
	SetSpeed(_speed * 6.f);
	SetDir(GetDir() * -1);
	POP(L"ParrySparkEffect", GetPosition());
	GET_SINGLE(ResourceManager)->Play(L"Parry");
	_hitEnemy = true;
	GetComponent<SpriteRenderer>()->SetTexture(_parriedTexture);
}

void EnemyBomb::OnPop()
{
	GetComponent<SpriteRenderer>()->SetTexture(_texture);
	_hitEnemy = false;
	_speed = 300.f;
	_damage = 20.f;
}