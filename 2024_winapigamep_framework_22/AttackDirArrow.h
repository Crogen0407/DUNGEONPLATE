#pragma once
#include "Object.h"
class SpriteRenderer;
class Texture;
class AttackDirArrow : public Object
{
public:
    AttackDirArrow();
    ~AttackDirArrow() override;
private:
    Texture* m_defaultTex;
private:
    SpriteRenderer* spriteRenderer;
    Vec2 dir;
    Object* parent;
public:
    void SetParent(Object* parent);
public:
    // Object을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render(HDC _hdc) override;
};
