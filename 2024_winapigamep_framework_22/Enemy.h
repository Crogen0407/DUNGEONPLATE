#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	Enemy();
	virtual ~Enemy();
public:
	virtual void Update() abstract;
	virtual void Render(HDC _hdc) abstract;
	virtual void OnDie();
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
};

