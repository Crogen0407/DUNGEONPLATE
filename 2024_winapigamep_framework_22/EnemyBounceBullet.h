#pragma once
#include "Projectile.h"

class EnemyBounceBullet : public Projectile
{
public:
	EnemyBounceBullet();
	~EnemyBounceBullet() override;
	void Update() override;
	void Render(HDC _hdc) override;
private:
	int bounceCnt = 5;
	int remainBounce;
};

