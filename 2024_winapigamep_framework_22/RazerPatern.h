#pragma once
#include "Patern.h"
class RazerPatern : public Patern
{
public:
	RazerPatern();
	~RazerPatern() override;

	// SkillSystem을(를) 통해 상속됨
	void Update() override;
	void UseSkill() override;
private:
	float _skillStartTime = 0;
	float _skillTime = 2.f;
};

