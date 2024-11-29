#pragma once
#include "PoolableObject.h"
class SpriteRenderer;
class Texture;
class Effect : public PoolableObject
{
public:
    Effect();
    ~Effect() override;
protected:
    SpriteRenderer* _spriteRenderer;
public:
    void Update() override;
    void LateUpdate() override;
    void Render(HDC _hdc) override;
public:
    virtual void OnPop() override {};
    virtual void OnPush() override {};
public:
    void SetTexture(Texture* texture);
    void SetTexture(wstring name, wstring path);
    void SetAngle(float angle, bool isDeg);
    void LookAt(Vec2 dir);
};

 