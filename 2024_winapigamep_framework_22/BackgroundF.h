#pragma once
#include "BackGround.h"
class BackgroundF :
    public Background
{
public:
    BackgroundF();
    ~BackgroundF() override;
public:
    void Update() override;
private:
    float _currentTime = 0;
    float _spawnDelayTime = 10.f;
};

