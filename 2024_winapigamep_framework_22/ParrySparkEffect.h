#pragma once
#include "Effect.h"
class Animator;
class ParrySparkEffect :
    public Effect
{
public:
    ParrySparkEffect();
    ~ParrySparkEffect() override;
public:
    void Update() override;
public:
    void OnPop() override;
    void OnPush() override;
private:
    Animator* _animator;
};

