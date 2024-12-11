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

	void Parry(Vec2 dir) override;
	void EnterCollision(Collider* _other) override;

	// Projectile을(를) 통해 상속됨
	void OnPop() override;
	void OnPush() override;
private:
	bool _isParry = false;
	float _rotation = 0;
	float _lifetime = 3.f;
	float _curTime = 0.f;
	float _prevAttack = 0;
	float _attackDelay = 1;

	Object* target;

};

