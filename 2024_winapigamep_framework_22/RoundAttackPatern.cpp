#include "pch.h"
#include "RoundAttackPatern.h"
#include "Projectile.h"
#include "EnemyBullet.h"
#include "SceneManager.h"
#include "Scene.h"
#include "AttackCompo.h"

RoundAttackPatern::RoundAttackPatern()
{
}

RoundAttackPatern::~RoundAttackPatern()
{
}

void RoundAttackPatern::Update()
{
}

void RoundAttackPatern::UseSkill()
{
	_isUsingSkill = false;
	_currentRotation = _startRotation;

	for (int i = 0; i < _attackCnt; i++)
	{
		Vec2 pos = _owner->GetPos();
		Vec2 dir = { cos(_currentRotation * Deg2Rad) , sin(_currentRotation * Deg2Rad) };

		_owner->GetComponent<AttackCompo>()->TryFireBullet(dir,500);

		/*Projectile* bullet = new EnemyBullet();
		bullet->SetPos(pos);
		bullet->SetDir(dir);

		GET_SINGLE(SceneManager)->GetCurrentScene()
			->AddObject(bullet, LAYER::PROJECTILE);*/

		_currentRotation += _rotateStep;
	}
}
