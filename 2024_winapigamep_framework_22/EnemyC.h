#pragma once
#include "Enemy.h"
class Texture;
class EnemyC : public Enemy
{
public:
	EnemyC();
	~EnemyC() override;

	// Enemy을(를) 통해 상속됨
	void Update() override;
private:
	float _shootDelay = 1;
	float _prevShootTime = 0;
	Texture* _texture;
};

