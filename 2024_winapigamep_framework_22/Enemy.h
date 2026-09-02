#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	Enemy();
	virtual ~Enemy();
public:
	void SetupSize(Vec2 size)
	{
		SetSize(size);
		_originSize = size;
	}
	virtual void Update();
	virtual void OnDie();
private:
	void OnHiting(float percent);
public:
	virtual void EnterCollision(Collider* _other) {}
	virtual void StayCollision(Collider* _other) {}
	virtual void ExitCollision(Collider* _other) {}
protected:
	int _originHp;
	int _giveExp;

	Object* _target;
	Vec2 _knockDir;
	float _rotation;
	bool _isDead;

private:
	bool _isHit = false;
	float _hitTime = 0.f;
	const float _hitDuration = 0.2f;
	Vec2 _originSize;
};

