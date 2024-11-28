#include "pch.h"
#include "TimeManager.h"
#include "AttackCompo.h"
#include "Projectile.h"
#include "SceneManager.h"
#include "Object.h"
#include "Scene.h"
#include "GuidedMissile.h"
#include "EnemyBullet.h"

AttackCompo::AttackCompo()
{
}

AttackCompo::~AttackCompo()
{
}

void AttackCompo::TryFire(Vec2 dir)
{
	Projectile* projectile = new EnemyBullet();
	projectile->SetPos(GetOwner()->GetPos());
	projectile->SetSize({ 10, 10 });

	GET_SINGLE(SceneManager)->GetCurrentScene()
		->AddObject(projectile, LAYER::PROJECTILE);

	projectile->SetDir(dir);
}

void AttackCompo::TryFireMissile()
{
	GuidedMissile* missile = new GuidedMissile();
	missile->SetPos(GetOwner()->GetPos());

	GET_SINGLE(SceneManager)->GetCurrentScene()
		->AddObject(missile, LAYER::PROJECTILE);
}

void AttackCompo::LateUpdate()
{
}

void AttackCompo::Render(HDC _hdc)
{
}
