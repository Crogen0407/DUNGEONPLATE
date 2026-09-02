#pragma once
#include "BackGround.h"
class BackgroundC :
    public Background
{
public:
    BackgroundC();
    ~BackgroundC() override;
public:
    void Update() override;
private:
    float _currentTime = 0;
    float _spawnDelayTime = 10.f;
};

