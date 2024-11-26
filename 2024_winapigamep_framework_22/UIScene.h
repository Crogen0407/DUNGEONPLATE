#pragma once
#include "Scene.h"
class Canvas;
class UIScene :
    public Scene
{
private:
    Canvas* canvas;
public:
    UIScene();
    ~UIScene();
public:
    void Init() override;
    void Update() override;
    void Render(HDC _hdc) override;
};

