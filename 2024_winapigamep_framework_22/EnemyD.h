#pragma once
#include "Enemy.h"
class Texture;
class RoundAttackPattern;
class EnemyD : public Enemy
{
public:
	EnemyD();
	~EnemyD()override;

	// Enemy을(를) 통해 상속됨
	void Update() override;
	void OnDie() override;
private:
	bool _isDead = false;
	float _startTime = 0;
	float _lifeTime = 3.f;
	float _moveSpeed = 300.f;
	Texture* _texture;
	RoundAttackPattern* _roundAttack;
};

