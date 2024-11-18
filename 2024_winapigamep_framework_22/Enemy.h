#pragma once
#include "Agent.h"

class Enemy : public Agent
{
public:
	Enemy();
	virtual ~Enemy();
public:
	virtual void Update() abstract;
	virtual void Render(HDC _hdc) abstract;
public:
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);
protected:
	int m_hp;
	int m_attack;
};

