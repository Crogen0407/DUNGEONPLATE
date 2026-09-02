#pragma once
#include "Projectile.h"

class EnemyBullet : public Projectile
{
public:
	EnemyBullet();
	~EnemyBullet() override;
	void Update() override;

	void Parry() override;
	void OnPop() override;
	void OnPush() override;
};

