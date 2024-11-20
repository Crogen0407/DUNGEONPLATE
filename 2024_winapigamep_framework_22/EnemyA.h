#pragma once
#include "Enemy.h"

class EnemyA : public Enemy
{
public:
	EnemyA();
	~EnemyA() override;
public:
	void Update() override; 
	void Render(HDC _hdc) override;
private:
	Object* player;
	float shootDelay = 1;
	float prevShootTime;
private:
	void Fire();
};

