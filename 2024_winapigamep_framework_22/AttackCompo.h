#pragma once
#include "Component.h"

class Object;

class AttackCompo : public Component
{
public:
	AttackCompo();
	virtual ~AttackCompo();
	void Init(float delay, Object* target)
	{
		this->shootDelay = delay;
		this->target = target;
	}
public:
	void TryFire();

protected:
	float shootDelay;
	float prevShootTime;
	Object* target;

	// Component을(를) 통해 상속됨
	void LateUpdate() override;
	void Render(HDC _hdc) override;
};

