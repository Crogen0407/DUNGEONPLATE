#pragma once
#include "Effect.h"
class Animator;
class HealEffect :
    public Effect
{
public:
    HealEffect();
    ~HealEffect() override;
public:
    void Update() override;
    void Render(HDC _hdc) override;
public:
    void OnPop() override;
    void OnPush() override;
private:
    Animator* _animator;
};

