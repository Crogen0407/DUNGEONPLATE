#pragma once
#include "Enemy.h"

class EnemyB : public Enemy
{
public:
	EnemyB();
	~EnemyB() override;
public:
	void Update() override;
	void Render(HDC _hdc) override;
private:
	float shootDelay = 1;
	float prevShootTime = 0;
	Object* target;
private:
	float prevDash = 0;
};

