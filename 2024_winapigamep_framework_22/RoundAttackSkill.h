#pragma once
#include "SkillSystem.h"

class RoundAttackSkill : public SkillSystem
{
public:
	RoundAttackSkill();
	virtual ~RoundAttackSkill();

	void Update() override;
	void UseSkill() override;

	void Init(float startRotation, float rotateStep, int attackCnt)
	{
		_startRotation = startRotation;
		_rotateStep = rotateStep;
		_attackCnt = attackCnt;
	}
private:
	int _attackCnt;
	float _startRotation;
	float _rotateStep;

	float _currentRotation;
};