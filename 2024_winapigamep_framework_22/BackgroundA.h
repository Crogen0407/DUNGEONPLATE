#pragma once
#include "BackGround.h"
class BackgroundA :
    public Background
{
public:
    BackgroundA();
    ~BackgroundA() override;
public:
    void Update() override;
private:
    float _currentTime = 0;
    float _spawnDelayTime = 10.f;
};

