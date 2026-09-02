#pragma once
#include "Enemy.h"

class EnemyA : public Enemy
{
public:
	EnemyA();
	~EnemyA() override;
public:
	void Update() override; 
private:
	float _shootDelay = 1;
	float _prevShootTime = 0;
private:
	float _prevDash = 0;
};

