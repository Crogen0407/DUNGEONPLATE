#pragma once
#include "Scene.h"

class Canvas;
class BackGround;
class Stage1;
class Stage2;
class Stage3;

class GameScene :
    public Scene
{
private:
    Stage1* stage1;
    Stage2* stage2;
    Stage3* stage3;
private:
    static const int _gridSize = 3;
    BackGround* _grid[_gridSize][_gridSize];
    int m_currentStage = 1;
    int frameCount = 0;
    int maxFrame = 300;
    bool isInitialized = false;
public:
    void Init() override;
    void Release() override;
    void Update() override;
    void Render(HDC hdc) override;
    void SetEnemyCount();
    BackGround* GetBackGroundAt(int x, int y);
private:
    EnemySpawner* _spawner;
    Canvas* _gameCanvas;
    Canvas* _skillCanvas;
};

