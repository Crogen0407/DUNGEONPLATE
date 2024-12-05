#pragma once
#include "Projectile.h"
class Texture;
class Object;
class Collider;
class Razer : public Projectile
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
		cout << _targetSize << '\n';
	}

	void EnterCollision(Collider* _other) override;
	void StayCollision(Collider* _other) override;
private:
	Texture* _texture;
	Object* _owner;
	float _targetSize = 0;
	float _lifeTime = 1.f;
	float _startLifeTime = 0.f;
	float _prevAttackTime = 0;
	float _attackDelay = 0.1f;

	// Projectile을(를) 통해 상속됨
	void OnPop() override;
	void OnPush() override;
};

