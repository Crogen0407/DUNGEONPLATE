#include "pch.h"
#include "EnemyC.h"
#include "ResourceManager.h"
#include "TimeManager.h"
#include "Texture.h"
#include "Animator.h"
#include "AttackCompo.h"
#include "HealthCompo.h"
#include "EventManager.h"

EnemyC::EnemyC()
{
	_giveExp = 4;
	SetSize({ 50,50 });
	_target = FindObject(L"Player", LAYER::PLAYER);
	_texture = LOADTEXTURE(L"Enemy06", L"Texture\\Enemy06.bmp");
	Vec2 texSize = Vec2((int)_texture->GetWidth() / 5, (int)_texture->GetHeight());

	AddComponent<Animator>();
	AddComponent<AttackCompo>();
	//AddComponent<HealthCompo>();

	GetComponent<Animator>()
		->CreateAnimation(L"Enemy06Idle", _texture, { 0,0 }, texSize, { (int)texSize.x, 0 }, 5, 0.2f, false);
	GetComponent<Animator>()->PlayAnimation(L"Enemy06Idle", true, 100);
	GetComponent<HealthCompo>()->SetOffsetY(60);
	GetComponent<HealthCompo>()->SetHp(30, 30);

	_prevShootTime = TIME;
}

EnemyC::~EnemyC()
{
}

void EnemyC::Update()
{
	if (_prevShootTime + _shootDelay < TIME)
	{
		_prevShootTime = TIME;

		Vec2 dir = _target->GetPos();
		dir -= GetPos();

		float rotation = atan2(dir.y, dir.x) * Rad2Deg;
		Vec2 dir1 = { cos((rotation - 30) * Deg2Rad) , sin((rotation - 30) * Deg2Rad) };
		Vec2 dir2 = { cos((rotation + 30) * Deg2Rad), sin((rotation + 30) * Deg2Rad) };

		GetComponent<AttackCompo>()->TryFireBullet(dir,500);
		GetComponent<AttackCompo>()->TryFireBullet(dir1,500);
		GetComponent<AttackCompo>()->TryFireBullet(dir2,500);
	}
}

void EnemyC::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void EnemyC::OnDie()
{
	Enemy::OnDie();
}
