#pragma once
#include "PoolableObject.h"
class Texture;
class Effect : public PoolableObject
{
public:
    Effect() = default;
    ~Effect() override = default;
protected:
    float _lifeTime = 1.f;
    float _curTime = 0.f;
public:
    virtual void Update() override  {}
    virtual void LateUpdate() override { PoolableObject::LateUpdate(); }
public:
    virtual void OnPop() override { }
    virtual void OnPush() override { _curTime = 0.f; }
};

 