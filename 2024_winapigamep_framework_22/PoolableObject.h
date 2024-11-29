#pragma once
#include "Object.h"
class PoolableObject : public Object
{
public:
	std::wstring name;
public:
	virtual void OnPop()
	{
		SetDead(false);
	}
	virtual void OnPush()
	{
		SetDead(true);
	}
public:
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC _hdc) override;
};

