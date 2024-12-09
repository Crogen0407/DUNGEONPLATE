#include "pch.h"
#include "RoundAttackPattern.h"
#include "Projectile.h"
#include "EnemyBullet.h"
#include "SceneManager.h"
#include "Scene.h"
#include "AttackCompo.h"

RoundAttackPattern::RoundAttackPattern()
{
}

RoundAttackPattern::~RoundAttackPattern()
{
}

void RoundAttackPattern::Update()
{
}

void RoundAttackPattern::UseSkill()
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
