#include "pch.h"
#include "RoundAttackSkill.h"
#include "Projectile.h"
#include "EnemyBullet.h"
#include "SceneManager.h"
#include "Scene.h"
#include "AttackCompo.h"

RoundAttackSkill::RoundAttackSkill()
{
}

RoundAttackSkill::~RoundAttackSkill()
{
}

void RoundAttackSkill::Update()
{
}

void RoundAttackSkill::UseSkill()
{
	_isUsingSkill = false;
	_currentRotation = _startRotation;

	for (int i = 0; i < _attackCnt; i++)
	{
		Vec2 pos = _owner->GetPos();
		Vec2 dir = { cos(_currentRotation * Deg2Rad) , sin(_currentRotation * Deg2Rad) };

		_owner->GetComponent<AttackCompo>()->TryFireBullet(dir);

		/*Projectile* bullet = new EnemyBullet();
		bullet->SetPos(pos);
		bullet->SetDir(dir);

		GET_SINGLE(SceneManager)->GetCurrentScene()
			->AddObject(bullet, LAYER::PROJECTILE);*/

		_currentRotation += _rotateStep;
	}
}
