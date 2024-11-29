#pragma once
#include "Object.h"
class Texture;
class Projectile : public Object
{
public:
	Projectile();
	virtual ~Projectile();
	void Update() abstract;
	void Render(HDC _hdc) abstract;
public:
	void SetDir(Vec2 dir)
	{
		_dir = dir;
		_dir.Normalize();
	}
	Vec2 GetDir()
	{
		return _dir;
	}
public:
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);
public:
	bool _canParry;
protected:
	//float m_dir;
	Vec2 _dir;
	Texture* _texture;
	float speed = 500.f;
};

