#pragma once
#include "SkillSystem.h"

class MissileSkill : public SkillSystem
{
public:
	MissileSkill();
	~MissileSkill() override;
public:
	void Update() override;
	void UseSkill() override;
private:
	int _currentIdx = 0;
	float _prevShootTime = 0;
};

