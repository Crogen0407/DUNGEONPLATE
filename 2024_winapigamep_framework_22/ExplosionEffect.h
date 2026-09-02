#pragma once
#include "Object.h"

class ExplosionEffect : public Object
{
public:
	ExplosionEffect(wstring name);
	~ExplosionEffect() override;

public:
    virtual void Update() override;
private:
	float _curTime;
	float _lifeTime = 0.35f;
};

