#pragma once
#include "Enemy.h"
class Texture;
class RoundAttackPatern;
class EnemyD : public Enemy
{
public:
	EnemyD();
	~EnemyD()override;

	// Enemy��(��) ���� ��ӵ�
	void Update() override;
	void Render(HDC _hdc) override;
	void OnDie() override;
private:
	bool _isDead = false;
	float _startTime = 0;
	float _lifeTime = 3.f;
	float _moveSpeed = 300.f;
	Texture* _texture;
	RoundAttackPatern* _roundAttack;
};

