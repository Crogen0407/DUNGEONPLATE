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
	// Component��(��) ���� ��ӵ�
	void LateUpdate() override;
	void Render(HDC _hdc) override;
};

