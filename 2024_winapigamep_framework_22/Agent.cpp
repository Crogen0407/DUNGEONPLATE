#include "pch.h"
#include "Agent.h"
#include "Animator.h"
#include "Object.h"

Agent::Agent()
{
	AddComponent<Animator>();
}

Agent::~Agent()
{
}

void Agent::Move(Vec2 dir)
{
	Vec2 position = GetPosition();
	position += dir;

	SetPosition(position);
}
