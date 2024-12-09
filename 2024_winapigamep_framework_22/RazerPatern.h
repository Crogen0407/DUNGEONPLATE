#pragma once
#include "Patern.h"
class RazerPatern : public Patern
{
public:
	RazerPatern();
	~RazerPatern() override;

	// SkillSystem��(��) ���� ��ӵ�
	void Update() override;
	void UseSkill() override;
private:
	float _skillStartTime = 0;
	float _skillTime = 2.f;
};

