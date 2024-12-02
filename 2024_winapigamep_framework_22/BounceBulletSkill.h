#pragma once
#include "SkillSystem.h"
class BounceBulletSkill : public SkillSystem
{
public:
	BounceBulletSkill();
	~BounceBulletSkill() override;

	// SkillSystem��(��) ���� ��ӵ�
	void Update() override;
	void UseSkill() override;
private:
	int _curBullet = 0;
	int _bulletCnt = 5;
	float _bulletDelay = 0.3f;
	float _prevShootTime = 0;
};

