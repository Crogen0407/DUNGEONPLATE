#pragma once
#include "Patern.h"

class RoundAttackSkill : public Patern
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