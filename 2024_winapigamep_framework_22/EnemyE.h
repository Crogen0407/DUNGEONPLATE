#pragma once
#include "Enemy.h"

class Texture;
class RoundAttackPattern;
class EnemyE : public Enemy
{
public:
	EnemyE();
	~EnemyE() override;

	void Update() override;
private:
	Texture* _texture;
	float _prevAttack = 0;
	float _attackDelay = 1.f;
	float _rotation = 0;
	RoundAttackPattern* _roundAttack;
};

