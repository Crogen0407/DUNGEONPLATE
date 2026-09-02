#include "pch.h"
#include "Movement.h"
#include "TimeManager.h"
#include "Object.h"

Movement::Movement()
{
}

Movement::~Movement()
{
}

void Movement::Move(Vec2 dir)
{
	if (_isDashing) return;

	Vec2 position = GetOwner()->GetPosition();
	position += dir;

	GetOwner()->SetPosition(position);
}

void Movement::Dash(Vec2 dir, float distance, float time)
{
	_dashStartTime = TIME;
	_dashDistance = distance;
	_isDashing = true;
	_dashTime = time;
	_dashDir = dir;
	_dashDir.Normalize();
}

void Movement::LateUpdate()
{
	if (_isDashing)
	{
		Vec2 position = GetOwner()->GetPosition();
		Vec2 size = GetOwner()->GetSize();
		position += _dashDir * _dashDistance * fDT;

		if (_dashStartTime + _dashTime < TIME || position.x < (size.x / 2) || position.x  > SCREEN_WIDTH - (size.x / 2)
			|| position.y < (size.y / 2) || position.y  > SCREEN_WIDTH - (size.y / 2))
			_isDashing = false;

		GetOwner()->SetPosition(position);
	}
}

void Movement::Render(ComPtr<ID2D1RenderTarget> renderTarget)
{
}
