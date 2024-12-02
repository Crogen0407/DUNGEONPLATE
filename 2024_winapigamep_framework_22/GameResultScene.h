#pragma once
#include "Scene.h"
class GameResultScene :
    public Scene
{
public:
    GameResultScene();
    ~GameResultScene() override;
public:
    void Init() override;
};

