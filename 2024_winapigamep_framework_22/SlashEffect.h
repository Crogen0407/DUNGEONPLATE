#pragma once
#include "Effect.h"
class SpriteRenderer;
class SlashEffect :
    public Effect
{
public:
    SlashEffect();
    ~SlashEffect() override;
public:
    void Update() override;
    void Render(HDC _hdc) override;
public:
    void OnPop() override;
    void OnPush() override;
public:
    void LookAt(const Vec2& dir);
public:
    float EaseOutCirc(float x)
    {
        return std::sqrtf(1 - std::powf(x - 1, 2));
    }
    float EaseInSine(float x)
    {
        return 1 - std::cosf((x * PI) / 2);
    }
private:
    SpriteRenderer* _spriteRenderer;
    Vec2 _dir;
};

