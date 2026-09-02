#pragma once
#include "Effect.h"
class Animator;
class HitEffect :
    public Effect
{
public:
    HitEffect();
    ~HitEffect() override;
public:
    void Update() override;
public:
    void OnPop() override;
    void OnPush() override;
private:
    Animator* _animator;
};


