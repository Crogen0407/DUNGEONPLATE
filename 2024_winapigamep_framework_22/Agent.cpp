#include "pch.h"
#include "Agent.h"

Agent::Agent()
{
	AddComponent<Animator>();
}

Agent::~Agent()
{
}

void Agent::Move(Vec2 dir)
{
	Vec2 position = GetPos();
	position += dir;

	SetPos(position);
}
