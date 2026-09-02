#pragma once
#include "BackGround.h"
class BackgroundE :
    public Background
{
public:
    BackgroundE();
    ~BackgroundE() override;
public:
    void Update() override;
private:
    float _currentTime = 0;
    float _spawnDelayTime = 10.f;
};

