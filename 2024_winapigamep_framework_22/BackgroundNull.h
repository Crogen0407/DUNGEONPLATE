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
};

