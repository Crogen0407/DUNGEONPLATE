#pragma once
#include "Scene.h"
class Canvas;
class UIScene :
    public Scene
{
private:
    Canvas* gameCanvas;
    Canvas* skillSelectCanvas;
public:
    UIScene();
    ~UIScene();
public:
    void Init() override;
    void Update() override;
};

