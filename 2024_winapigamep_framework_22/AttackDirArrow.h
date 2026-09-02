#pragma once
#include "Object.h"
class SpriteRenderer;
class Texture;
class AttackDirArrow : public Object
{
public:
    AttackDirArrow();
    ~AttackDirArrow() override;
public:
    void Update() override;
private:
    Texture* m_defaultTex;
private:
    SpriteRenderer* spriteRenderer;
    Vec2 dir;
    Object* parent;
public:
    void SetParent(Object* parent);
};
