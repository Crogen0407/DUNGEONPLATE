#include "pch.h"
#include "EnemyBounceBullet.h"
#include "TimeManager.h"
#include "PoolManager.h"
#include "Collider.h"
#include "SpriteRenderer.h"

EnemyBounceBullet::EnemyBounceBullet()
{
	_damage = 10;
	_poolName = L"EnemyBounceBullet";
	_texture = LOADTEXTURE(L"EnemyBounceBullet", L"Texture\\EnemyBounceBullet.bmp");

	SetSize({ 20.f,20.f });
	AddComponent<SpriteRenderer>();
	AddComponent<Collider>();

	GetComponent<Collider>()->SetSize({ 20.f,20.f });
	GetComponent<SpriteRenderer>()->SetTexture(_texture);
}

EnemyBounceBullet::~EnemyBounceBullet()
{
}

void EnemyBounceBullet::Update()
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();

	vPos.x += _dir.x * _speed * fDT;
	vPos.y += _dir.y * _speed * fDT;
	SetPos(vPos);

	if (vPos.x < vSize.x / 2 || vPos.x > SCREEN_WIDTH - vSize.x / 2)
	{
		_dir = _dir + Vec2(-2, 0) * -_dir.Dot(Vec2(-1, 0));
		remainBounce--;
	}

	if (vPos.y < vSize.y / 2 || vPos.y > SCREEN_HEIGHT - vSize.y / 2)
	{
		_dir = _dir + Vec2(0, -2) * -_dir.Dot(Vec2(0, -1));
		remainBounce--;
	}


	if (remainBounce <= 0)
		PUSH(_poolName, this);
}

void EnemyBounceBullet::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void EnemyBounceBullet::OnPop()
{
	_hitEnemy = false;
	remainBounce = bounceCnt;
}

void EnemyBounceBullet::OnPush()
{
}
