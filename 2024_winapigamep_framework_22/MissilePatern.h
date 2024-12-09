#pragma once
#include "Patern.h"

class MissilePatern : public Patern
{
public:
	MissilePatern();
	~MissilePatern() override;
public:
	void Update() override;
	void UseSkill() override;
private:
	int _currentIdx = 0;
	float _prevShootTime = 0;
};

