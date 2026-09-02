#pragma once
#include "Object.h"

class Agent : public Object
{
public :
	Agent();
	virtual ~Agent() override;
protected:
	void Move(Vec2 dir);
};

