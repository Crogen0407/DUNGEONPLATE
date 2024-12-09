#pragma once
#include "Patern.h"
#include "RoundAttackPatern.h"

class EnemyPaternA : public Patern
{
public:
	EnemyPaternA();
	~EnemyPaternA() override;

	// SkillSystem��(��) ���� ��ӵ�
	void Update() override;
	void UseSkill() override;
	void SetOwner(Object* owner)
	{
		_owner = owner;
		_roundAttack->SetOwner(owner);
	}
private:
	RoundAttackPatern* _roundAttack;
	float _prevAttack;
	int _attackCnt = 3;
	int _curAttackCnt = 0;
};

