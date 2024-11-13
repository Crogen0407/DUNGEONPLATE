#pragma once
#include "Scene.h"
class GameScene :
    public Scene
{
public:
    // Scene을(를) 통해 상속됨
    virtual void Init() override;
};

