#pragma once
#include "Component.h"

class Object;

class AttackCompo : public Component
{
public:
	AttackCompo();
	virtual ~AttackCompo();
public:
	void TryFire(Vec2 dir);
	void TryFireMissile();

protected:
	// Component을(를) 통해 상속됨
	void LateUpdate() override;
	void Render(HDC _hdc) override;
};

