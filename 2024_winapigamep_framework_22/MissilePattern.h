#pragma once
#include "Pattern.h"

class MissilePattern : public Pattern
{
public:
	MissilePattern();
	~MissilePattern() override;
public:
	void Update() override;
	void UseSkill() override;
private:
	int _currentIdx = 0;
	float _prevShootTime = 0;
};

