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
		= dynamic_cast<EnemyBullet*>(POP(L"EnemyBullet", GetOwner()->GetPosition()));
	projectile->SetDir(dir);
	projectile->SetSpeed(speed);
}

void AttackCompo::TryFireBounceBullet(Vec2 dir)
{
	EnemyBounceBullet* bounceBullet 
		= dynamic_cast<EnemyBounceBullet*>(POP(L"EnemyBounceBullet", GetOwner()->GetPosition()));
	bounceBullet->SetDir(dir);
	bounceBullet->SetSpeed(700);
}

void AttackCompo::TryFireRazer(float lifeTime)
{
	Razer* razer = new Razer(lifeTime);
	razer->SetOwner(GetOwner());

	GET_SINGLE(SceneManager)->GetCurrentScene()
		->AddObject(razer, LAYER::PROJECTILE);
}

void AttackCompo::LateUpdate()
{
}

void AttackCompo::Render(ComPtr<ID2D1RenderTarget> renderTarget)
{
}

void AttackCompo::TryFireMissile(Vec2 dir)
{
	GuidedMissile* missile
		= dynamic_cast<GuidedMissile*>(POP(L"GuidedMissile", GetOwner()->GetPosition()));
	missile->SetDir(dir);
}