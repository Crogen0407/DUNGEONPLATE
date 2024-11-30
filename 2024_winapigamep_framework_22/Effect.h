#pragma once
#include "PoolableObject.h"
class Texture;
class Effect : public PoolableObject
{
public:
    Effect();
    ~Effect() override;
protected:
    float _lifeTime = 0.5f;
    float _curTime = 0.f;
public:
    virtual void Update() override;
    virtual void LateUpdate() abstract override;
    virtual void Render(HDC _hdc) abstract override;
public:
    virtual void OnPop() override { }
    virtual void OnPush() override { _curTime = 0.f; }
};

 