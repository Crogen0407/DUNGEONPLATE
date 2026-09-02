#pragma once
#include "Object.h"

class PoolableObject : public Object
{
public:
	PoolableObject();
	virtual ~PoolableObject() override;
public:
	virtual void OnPop() abstract;
	virtual void OnPush() abstract;
public:
	virtual void Update() override;
	virtual void LateUpdate() override;
};

