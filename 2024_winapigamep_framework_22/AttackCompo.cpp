#include "pch.h"
#include "TimeManager.h"
#include "AttackCompo.h"
#include "Projectile.h"
#include "SceneManager.h"
#include "Object.h"
#include "Scene.h"

AttackCompo::AttackCompo() :
	shootDelay{ 0 },
	prevShootTime{ 0 },
	target{ nullptr }
{
}

AttackCompo::~AttackCompo()
{
}

void AttackCompo::TryFire()
{
	if (prevShootTime + shootDelay < TIME)
	{
		prevShootTime = TIME;

		Vec2 dir = target->GetPos();
		dir -= GetOwner()->GetPos();

		Projectile* projectile = new Projectile();
		projectile->SetPos(GetOwner()->GetPos());
		projectile->SetSize({ 10, 10 });

		GET_SINGLE(SceneManager)->GetCurrentScene()
			->AddObject(projectile, LAYER::PROJECTILE);

		projectile->SetDir(dir);
	}
}

void AttackCompo::LateUpdate()
{
}

void AttackCompo::Render(HDC _hdc)
{
}
