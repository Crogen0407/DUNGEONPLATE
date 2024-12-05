#pragma once
#include "Projectile.h"
class Texture;
class Collider;

class GuidedMissile : public Projectile
{
public:
	GuidedMissile();
	~GuidedMissile() override;
	void Update() override;
	void Render(HDC _hdc) override;
	void SetDir(Vec2 dir) override;

	void Parry() override;
	void EnterCollision(Collider* _other) override;
private:
	bool _isParry = false;
	float _rotation = 0;
	float _lifetime = 3.f;
	float _spawnedTime = 0.f;
	float _prevAttack = 0;
	float _attackDelay = 0.5f;

	Object* target;
};

