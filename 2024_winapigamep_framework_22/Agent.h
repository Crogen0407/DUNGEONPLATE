#pragma once
#include "Animator.h"
#include "Object.h"

class Agent : public Object
{
public :
	Agent();
	virtual ~Agent();
protected:
	void Move(Vec2 dir);
};

