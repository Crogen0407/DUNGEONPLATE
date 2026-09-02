#pragma once
#include "Enemy.h"

class Texture;
class EnemyF : public Enemy
{
public:
	EnemyF();
	~EnemyF() override;

	void Update() override;
public:
	void OnMove();
	void OnShoot();
private:
	Texture* _texture;
	float _shootDelay = 1;
	float _prevShootTime = 0;

	float _moveDelay = 2;
	float _prevMoveTime = 0;
};

