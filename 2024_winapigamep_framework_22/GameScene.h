#pragma once
#include "Scene.h"
class Canvas;
class EnemySpawner;
class GameScene :
    public Scene
{
public:
    ~GameScene();
public:
    virtual void Init() override;
    void Update() override;
    void Render(HDC hdc) override;
private:
    EnemySpawner* _spawner;
    Canvas* _gameCanvas;
    Canvas* _skillCanvas;
};

