#pragma once
#include "PoolableObject.h"
class Texture;
class Projectile : public PoolableObject
{
public:
	Projectile();
	virtual ~Projectile();
	void Update() abstract;
	void Render(HDC _hdc) abstract;
public:
	virtual void SetDir(Vec2 dir)
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
	void SetSpeed(float speed) { _speed = speed; }
	virtual void Parry(Vec2 dir);
	bool _hitEnemy = false;
protected:
	//float m_dir;
	wstring _poolName;
	Vec2 _dir;
	Texture* _texture;
	float _speed = 500.f;
	int _damage;
public:
	virtual void OnPop() override;
	virtual void OnPush() override;
};

