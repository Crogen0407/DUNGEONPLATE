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
	if (isDashing) return;

	Vec2 position = GetOwner()->GetPos();
	position += dir;

	GetOwner()->SetPos(position);
}

void Movement::Dash(Vec2 dir, float speed, float time)
{
	dashStartTime = TIME;
	dashSpeed = speed;
	isDashing = true;
	dashTime = time;
	dashDir = dir;
}

void Movement::LateUpdate()
{
	if (isDashing)
	{
		if (dashStartTime + dashTime < TIME)
		{
			isDashing = false;
		}

		Vec2 position = GetOwner()->GetPos();
		position += dashDir;

		GetOwner()->SetPos(position);
	}
}

void Movement::Render(HDC _hdc)
{
}
