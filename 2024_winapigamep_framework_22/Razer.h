#pragma once
#include "Object.h"
class Texture;
class Collider;
class Razer : public Object
{
public:
	Razer(float lifeTime);
	~Razer() override;

	// Projectile을(를) 통해 상속됨
	void Update() override;
	void Render(HDC _hdc) override;
	void SetOwner(Object* owner)
	{
		_owner = owner;
		_targetSize = SCREEN_HEIGHT - owner->GetPos().y + 50;
	}

	void EnterCollision(Collider* _other) override;
	void StayCollision(Collider* _other) override;
private:
	Texture* _texture;
	Object* _owner;
	float _damage;
	float _targetSize = 0;
	float _lifeTime = 1.f;
	float _startLifeTime = 0.f;
	float _prevAttackTime = 0;
	float _attackDelay = 0.1f;
};

