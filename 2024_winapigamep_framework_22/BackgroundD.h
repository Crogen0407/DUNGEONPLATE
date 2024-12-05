#pragma once
#include "BackGround.h"
class BackgroundD :
    public Background
{
public:
    BackgroundD();
    ~BackgroundD() override;
public:
    void Update() override;
private:
    float _currentTime = 0;
    float _spawnDelayTime = 10.f;
};