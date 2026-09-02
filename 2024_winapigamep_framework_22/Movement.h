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
	bool _isDashing = false;

	Vec2 _dashDir = { 0,0 };
	float _dashStartTime = 0;
	float _dashDistance = 0;
	float _dashTime = 0;

	// Component을(를) 통해 상속됨
	void LateUpdate() override;
	void Render(ComPtr<ID2D1RenderTarget> renderTarget) override;
};

