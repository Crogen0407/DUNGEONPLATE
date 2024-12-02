#pragma once
#include "Scene.h"
class HelpScene :
    public Scene
{
public:
    HelpScene();
    ~HelpScene() override;
public:
    void Init() override;
};

