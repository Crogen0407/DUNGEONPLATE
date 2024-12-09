#include "pch.h"
#include "EnemyPatternA.h"
#include "RoundAttackPattern.h"
#include "TimeManager.h"

EnemyPatternA::EnemyPatternA()
{
	_roundAttack = new RoundAttackPattern();
}

EnemyPatternA::~EnemyPatternA()
{
	delete(_roundAttack);
}

void EnemyPatternA::Update()
{
	if (!_isUsingSkill) return;

	if (_prevAttack + 0.1f < TIME)
	{
		_prevAttack = TIME;

		_roundAttack->Init(10 * _curAttackCnt, 30, 12);
		_roundAttack->UseSkill();

		if (++_curAttackCnt >= _attackCnt)
			_isUsingSkill = false;
	}
}

void EnemyPatternA::UseSkill()
{
	_isUsingSkill = true;
	_prevAttack = TIME;
	_curAttackCnt = 0;
}
