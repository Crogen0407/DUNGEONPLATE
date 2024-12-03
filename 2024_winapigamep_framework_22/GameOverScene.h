#pragma once
#include "Scene.h"
class Canvas;
class GameOverScene :
    public Scene
{
public:
    void Init() override;
    void Release() override;
    void Update() override;
    void LateUpdate() override;
    void Render(HDC _hdc) override;
private:
    Canvas* _canvas;
};

