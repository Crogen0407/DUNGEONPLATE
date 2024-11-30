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
private:
	float speed = 100.f;
	Vec2 attackDir;
	float parryDist = 100.f;
	float parryingTime = 0.1f;
	bool isParrying = false;

	float curParryTime;
	float parryCoolTime = 0.5f;
};

