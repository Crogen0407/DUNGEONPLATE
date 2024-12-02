#pragma once
#include "Scene.h"

class BackGround;

class StageScene  : 
	public Scene
{
private:
    static const int gridSize = 3;
    BackGround* grid[gridSize][gridSize];
    //int frameCount = 0;  
    //const int framesToClear = 300;
    int enemyCount;
    int m_currentStage = 1;
public:
    void Init() override;
    void Render(HDC _hdc);
    void Update();
    void SetEnemyCount();
    BackGround* GetBackGroundAt(int x, int y);
};

