#pragma once
#include "Patern.h"
class BounceBulletPatern : public Patern
{
public:
	BounceBulletPatern();
	~BounceBulletPatern() override;

	// SkillSystem��(��) ���� ��ӵ�
	void Update() override;
	void UseSkill() override;
private:
	int _curBullet = 0;
	int _bulletCnt = 5;
	float _bulletDelay = 0.3f;
	float _prevShootTime = 0;
};

