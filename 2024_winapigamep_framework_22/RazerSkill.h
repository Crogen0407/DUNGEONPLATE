#pragma once
#include "SkillSystem.h"
class RazerSkill : public SkillSystem
{
public:
	RazerSkill();
	~RazerSkill() override;

	// SkillSystem��(��) ���� ��ӵ�
	void Update() override;
	void UseSkill() override;
private:
	float _skillStartTime = 0;
	float _skillTime = 2.f;
};

