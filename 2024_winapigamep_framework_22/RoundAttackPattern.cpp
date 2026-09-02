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
		Vec2 pos = _owner->GetPosition();
		Vec2 dir = { cos(_currentRotation * Deg2Rad) , sin(_currentRotation * Deg2Rad) };

		_owner->GetComponent<AttackCompo>()->TryFireBullet(dir, 350);

		_currentRotation += _rotateStep;
	}
}
