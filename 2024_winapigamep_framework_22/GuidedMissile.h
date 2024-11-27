#pragma once
#include "Object.h"
class Texture;

class GuidedMissile : public Object
{
public:
	GuidedMissile();
	~GuidedMissile();
	void Update() override;
	void Render(HDC _hdc) override;
public:
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);
private:
	Texture* tex;
	float speed = 300.f;
	float lifetime = 3.f;
	float spawnedTime = 0.f;

	Vec2 currentDir = { 0,0 };
	Object* target;
};

