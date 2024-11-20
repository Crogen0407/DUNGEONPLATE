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
private:
	SpriteRenderer* _spriteRenderer;
	Texture* m_pTex;
	float speed = 100.f;
};

