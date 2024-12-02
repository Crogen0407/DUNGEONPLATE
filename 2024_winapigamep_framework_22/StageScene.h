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
    int m_currentStage = 0;
public:
    void Init() override;
    void Render(HDC _hdc);
    void Update();
    void SetEnemyCount();
    BackGround* GetBackGroundAt(int x, int y);
};

