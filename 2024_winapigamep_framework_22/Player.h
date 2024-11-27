#pragma once
#include "Agent.h"
class HealthCompo;
class SpriteRenderer;
class Texture;
class Player : public Agent
{
public:
	Player();
	~Player() override;
public:
	void Update() override;
	void Render(HDC _hdc) override;

	void Parry();
public:
	void EnterCollision(Collider* _other)	override;
	void StayCollision(Collider* _other)	override;
	void ExitCollision(Collider* _other)	override;
private:
	SpriteRenderer* _spriteRenderer;
	HealthCompo* healthCompo;
	Texture* m_pTex;
	float speed = 100.f;
};

