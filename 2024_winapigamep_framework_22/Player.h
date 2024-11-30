#pragma once
#include "Agent.h"
#include "Action.h"

class SpriteRenderer;
class PlayerHealthCompo;
class Player : public Agent
{
public:
	Player();
	~Player() override;
public:
	void Update() override;
	void Render(HDC _hdc) override;

	void Parry();
	void Parrying();
public:
	void EnterCollision(Collider* _other)	override;
	void StayCollision(Collider* _other)	override;
	void ExitCollision(Collider* _other)	override;
private:
	SpriteRenderer* _spriteRenderer;
	PlayerHealthCompo* healthCompo;
	Collider* collider;
//ÆÐ¸µ
public:
	Action<float> ParryCoolTimeEvent;
public:
	//MoveSpeed
	const float GetMoveSpeed() const
	{
		return speed;
	}
	void SetMoveSpeed(const float& speed)
	{
		this->speed = speed;
	}

	//ParryCoolTime
	const float GetParryCoolTime() const
	{
		return parryCoolTime;
	}
	void SetParryCoolTime(const float& parryCoolTime)
	{
		this->parryCoolTime = parryCoolTime;
	}

	//AttackDir
	const Vec2 GetAttackDir() const
	{
		return attackDir;
	}

	//CanMove
	const bool GetCanMove() const
	{
		return canMove;
	}
	void SetCanMove(const bool& canMove)
	{
		this->canMove = canMove;
	}

private:
	float speed = 100.f;
	Vec2 attackDir;
	float parryDist = 100.f;
	float parryingTime = 0.1f;
	bool isParrying = false;
	bool canMove;
	float curParryTime;
	float parryCoolTime = 0.5f;
};

