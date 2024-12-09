#pragma once
#include "Pattern.h"
#include "RoundAttackPattern.h"

class EnemyPatternA : public Pattern
{
public:
	EnemyPatternA();
	~EnemyPatternA() override;

	// SkillSystem을(를) 통해 상속됨
	void Update() override;
	void UseSkill() override;
	void SetOwner(Object* owner)
	{
		_owner = owner;
		_roundAttack->SetOwner(owner);
	}
private:
	RoundAttackPattern* _roundAttack;
	float _prevAttack;
	int _attackCnt = 3;
	int _curAttackCnt = 0;
};

