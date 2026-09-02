#pragma once
#include "Enemy.h"

class Texture;
class EnemyB : public Enemy
{
public:
	EnemyB();
	~EnemyB() override;
public:
	void Update() override;
private:
	float shootDelay = 1;
	float prevShootTime = 0;
	Texture* texture;
private:
	float prevDash = 0;
};

