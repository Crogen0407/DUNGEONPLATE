#pragma once
#include "Projectile.h"
class Texture;

class GuidedMissile : public Projectile
{
public:
	GuidedMissile();
	~GuidedMissile() override;
	void Update() override;
	void Render(HDC _hdc) override;
private:
	float _rotation = 0;
	float lifetime = 2.f;
	float spawnedTime = 0.f;

	Object* target;
};

