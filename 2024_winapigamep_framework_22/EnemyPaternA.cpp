#include "pch.h"
#include "EnemyPaternA.h"
#include "RoundAttackSkill.h"
#include "TimeManager.h"

EnemyPaternA::EnemyPaternA()
{
	_roundAttack = new RoundAttackSkill();
}

EnemyPaternA::~EnemyPaternA()
{
	delete(_roundAttack);
}

void EnemyPaternA::Update()
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

void EnemyPaternA::UseSkill()
{
	_isUsingSkill = true;
	_prevAttack = TIME;
	_curAttackCnt = 0;
}
