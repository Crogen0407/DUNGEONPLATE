#pragma once
#include "Enemy.h"

class Texture;
class RoundAttackPattern;
class EnemyE : public Enemy
{
public:
	EnemyE();
	~EnemyE() override;

	// Enemy을(를) 통해 상속됨
	void Update() override;
	void Render(HDC _hdc) override;
private:
	Texture* _texture;
	float _prevAttack = 0;
	float _attackDelay = 1.f;
	float _rotation = 0;
	RoundAttackPattern* _roundAttack;
};

