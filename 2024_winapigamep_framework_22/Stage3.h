#pragma once
#include "Stage.h"
class Stage3 : public Stage
{
public:
    Stage3();
    ~Stage3() override;
public:
    void Init() override;
    void Update() override;
    void Release() override;
};

