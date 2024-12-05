#pragma once
#include "Scene.h"
class Canvas;
class HelpScene :
    public Scene
{
public:
    HelpScene();
    ~HelpScene() override;
public:
    void Init() override;
    void Release() override;
private:
    Canvas* _canvas;
};

