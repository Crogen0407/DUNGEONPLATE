#pragma once
#include "Agent.h"

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
	void Parrying();
private:
	SpriteRenderer* _spriteRenderer;
	Texture* m_pTex;
	float speed = 100.f;
//ÆÐ¸µ
private:
	float parryDist = 70.f;
	float parryingTime = 0.1f;
	bool isParrying = false;

	float prevParryTime;
	float parryCoolTime = 0.5f;
};

