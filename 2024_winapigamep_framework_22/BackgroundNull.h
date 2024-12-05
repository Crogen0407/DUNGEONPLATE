#pragma once
#include "BackGround.h"
class BackgroundNull :
    public Background
{
public:
    BackgroundNull();
    ~BackgroundNull() override;
public:
    void Update() override;
private:
    float _currentTime = 0;
    float _spawnDelayTime = 10.f;
};

