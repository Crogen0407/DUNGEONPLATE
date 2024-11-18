#pragma once
#include "Agent.h"

class Texture;
class Player : public Agent
{
public:
	Player();
	~Player();
public:
	void Update() override;
	void Render(HDC _hdc) override;

	void Parry();
private:
	Texture* m_pTex;
	float speed = 100.f;
};

