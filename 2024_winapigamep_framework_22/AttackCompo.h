#pragma once
#include "Component.h"

class Object;

class AttackCompo : public Component
{
public:
	AttackCompo();
	virtual ~AttackCompo();

public:
	void TryFireBullet(Vec2 dir, float speed);
	void TryFireMissile(Vec2 dir);
	void TryFireBounceBullet(Vec2 dir);
	void TryFireRazer(float lifeTime);

public:
	void LateUpdate() override;
	void Render(ComPtr<ID2D1RenderTarget> renderTarget) override;
};

