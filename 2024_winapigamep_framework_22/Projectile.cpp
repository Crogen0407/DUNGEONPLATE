#include "pch.h"
#include "Projectile.h"
#include "TimeManager.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Collider.h"
#include "HealthCompo.h"
#include "PoolableObject.h"
#include "Scene.h"
#include "PoolManager.h"
#include "Object.h"
#include "Component.h"

Projectile::Projectile() : _dir(1.f, 1.f)
{

}

Projectile::~Projectile()
{
}

void Projectile::EnterCollision(Collider* _other)
{
	LAYER layer =
		GET_SINGLE(SceneManager)->GetCurrentScene()->GetLayer(_other->GetOwner());

	if (layer == LAYER::PLAYER || (layer == LAYER::ENEMY && _hitEnemy))
	{
		HealthCompo* health = _other->GetOwner()->GetComponent<HealthCompo>();

		if (health != nullptr)
			health->ApplyDamage(_damage);

		PUSH(_poolName, this);
	}
}

void Projectile::StayCollision(Collider* _other)
{
}

void Projectile::ExitCollision(Collider* _other)
{
}

void Projectile::Parry()
{
	SetSpeed(_speed * 3.f);
	SetDir(_dir * -1);
	POP(L"ParrySparkEffect", GetPos());
	GET_SINGLE(ResourceManager)->Play(L"Parry");
	_hitEnemy = true;
}

void Projectile::OnPop()
{
}

void Projectile::OnPush()
{
}
