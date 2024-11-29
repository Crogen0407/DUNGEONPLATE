#pragma once
#include "Effect.h"
class SlashEffect :
    public Effect
{
public:
    SlashEffect();
    ~SlashEffect() override;
private:
    float lifeTime = 0.5f;
    float curTime = 0.f;
public:
    void Update() override;
public:
    void OnPop() override;
    void OnPush() override;
};

