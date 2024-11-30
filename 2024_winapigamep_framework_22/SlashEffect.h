#pragma once
#include "Effect.h"
class SpriteRenderer;
class SlashEffect :
    public Effect
{
public:
    SlashEffect();
    ~SlashEffect() override;
private:
    SpriteRenderer* _spriteRenderer;
    Vec2 _dir;
public:
    void Update() override;
    void LateUpdate() override;
    void Render(HDC _hdc) override;
public:
    void OnPop() override;
    void OnPush() override;
public:
    void LookAt(const Vec2& dir);
};

