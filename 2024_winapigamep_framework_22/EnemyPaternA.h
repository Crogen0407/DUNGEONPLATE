#pragma once
#include "SkillSystem.h"
#include "RoundAttackSkill.h"

class EnemyPaternA : public SkillSystem
{
public:
	EnemyPaternA();
	~EnemyPaternA() override;

	// SkillSystem을(를) 통해 상속됨
	void Update() override;
	void UseSkill() override;
	void SetOwner(Object* owner)
	{
		_owner = owner;
		_roundAttack->SetOwner(owner);
	}
private:
	RoundAttackSkill* _roundAttack;
	float _prevAttack;
	int _attackCnt = 3;
	int _curAttackCnt = 0;
};

