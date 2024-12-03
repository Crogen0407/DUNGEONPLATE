#pragma once
#include "Scene.h"
class Canvas;
class GameScene :
    public Scene
{
public:
    void Init() override;
    void Release() override;
    void Update() override;
    void Render(HDC hdc) override;
private:
    Canvas* _gameCanvas;
    Canvas* _skillCanvas;
};

