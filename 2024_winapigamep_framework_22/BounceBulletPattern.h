#pragma once
#include "Pattern.h"
class BounceBulletPattern : public Pattern
{
public:
	BounceBulletPattern();
	~BounceBulletPattern() override;

	// SkillSystem을(를) 통해 상속됨
	void Update() override;
	void UseSkill() override;
private:
	int _curBullet = 0;
	int _bulletCnt = 5;
	float _bulletDelay = 0.3f;
	float _prevShootTime = 0;
};

