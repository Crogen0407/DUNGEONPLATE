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

AttackCompo::AttackCompo()
{
}

AttackCompo::~AttackCompo()
{
}

void AttackCompo::TryFireBullet(Vec2 dir)
{
	Projectile* projectile = new EnemyBullet();
	projectile->SetPos(GetOwner()->GetPos());
	projectile->SetDir(dir);

	GET_SINGLE(SceneManager)->GetCurrentScene()
		->AddObject(projectile, LAYER::PROJECTILE);

}

void AttackCompo::TryFireBounceBullet(Vec2 dir)
{
	Projectile* missile = new EnemyBounceBullet();
	missile->SetPos(GetOwner()->GetPos());
	missile->SetDir(dir);

	GET_SINGLE(SceneManager)->GetCurrentScene()
		->AddObject(missile, LAYER::PROJECTILE);
}

void AttackCompo::TryFireMissile(Vec2 dir)
{
	Projectile* missile = new GuidedMissile();
	missile->SetPos(GetOwner()->GetPos());
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
