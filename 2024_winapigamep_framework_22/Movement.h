#pragma once
#include "Component.h"

class Movement : public Component
{
public:
	Movement();
	virtual ~Movement();
public:
	void Move(Vec2 dir);
	void Dash(Vec2 dir, float speed, float time);
private:
	bool isDashing = false;

	Vec2 dashDir = { 0,0 };
	float dashStartTime = 0;
	float dashSpeed = 0;
	float dashTime = 0;

	// Component을(를) 통해 상속됨
	void LateUpdate() override;
	void Render(HDC _hdc) override;
};

