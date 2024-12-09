#pragma once
#include "Enemy.h"

class Texture;
class RoundAttackPatern;
class EnemyE : public Enemy
{
public:
	EnemyE();
	~EnemyE() override;

	// Enemy��(��) ���� ��ӵ�
	void Update() override;
	void Render(HDC _hdc) override;
private:
	Texture* _texture;
	float _prevAttack = 0;
	float _attackDelay = 1.f;
	float _rotation = 0;
	RoundAttackPatern* _roundAttack;
};

