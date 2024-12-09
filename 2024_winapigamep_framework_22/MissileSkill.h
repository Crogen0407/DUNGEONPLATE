#pragma once
#include "Patern.h"

class MissileSkill : public Patern
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

