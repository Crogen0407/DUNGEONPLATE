#include "pch.h"
#include "TimeManager.h"
#include "AttackCompo.h"
#include "Projectile.h"
#include "SceneManager.h"
#include "Object.h"
#include "Scene.h"
#include "GuidedMissile.h"
#include "EnemyBullet.h"
#include "EnemyBounceBullet.h"
#include "Razer.h"
#include "PoolManager.h"
#include "PoolableObject.h"

AttackCompo::AttackCompo()
{
}

AttackCompo::~AttackCompo()
{
}

void AttackCompo::TryFireBullet(Vec2 dir, float speed)
{
	EnemyBullet* projectile 
		= dynamic_cast<EnemyBullet*>(POP(L"EnemyBullet", GetOwner()->GetPos()));
	projectile->SetDir(dir);
	projectile->SetSpeed(speed);
}

void AttackCompo::TryFireBounceBullet(Vec2 dir)
{
	EnemyBounceBullet* missile 
		= dynamic_cast<EnemyBounceBullet*>(POP(L"EnemyBounceBullet", GetOwner()->GetPos()));
	missile->SetDir(dir);

	GET_SINGLE(SceneManager)->GetCurrentScene()
		->AddObject(missile, LAYER::PROJECTILE);
}

void AttackCompo::TryFireRazer(float lifeTime)
{
	Razer* razer = new Razer(lifeTime);
	razer->SetDir({ 0,1 });
	razer->SetOwner(GetOwner());

	GET_SINGLE(SceneManager)->GetCurrentScene()
		->AddObject(razer, LAYER::PROJECTILE);
}

void AttackCompo::TryFireMissile(Vec2 dir)
{
	GuidedMissile* missile
		= dynamic_cast<GuidedMissile*>(POP(L"GuidedMissile", GetOwner()->GetPos()));
	missile->SetDir(dir);

	GET_SINGLE(SceneManager)->GetCurrentScene()
		->AddObject(missile, LAYER::PROJECTILE);
}

void AttackCompo::LateUpdate()
{
}

void AttackCompo::Render(HDC _hdc)
{
}
