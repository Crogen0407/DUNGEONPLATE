#pragma once
#include "BackGround.h"
class BackgroundB :
    public Background
{
public:
    BackgroundB();
    ~BackgroundB() override;
public:
    void Update() override;
private:
    float _currentTime = 0;
    float _spawnDelayTime = 10.f;
};

