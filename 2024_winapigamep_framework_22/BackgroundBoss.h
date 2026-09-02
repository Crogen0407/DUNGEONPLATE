#pragma once
#include "BackGround.h"
class BackgroundBoss :
    public Background
{
public:
    BackgroundBoss();
    ~BackgroundBoss() override;
public:
    void Update() override;
private:
    float _currentTime = 0;
    float _spawnDelayTime = 10.f;
};

