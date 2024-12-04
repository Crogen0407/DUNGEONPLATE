#pragma once
#include "Scene.h"

class Background;
class StageScene  : 
	public Scene
{
private:
    static const int gridSize = 3;
    Background* grid[gridSize][gridSize];
    //int frameCount = 0;  
    //const int framesToClear = 300;
    int m_currentStage = 0;
public:
    void Init() override;
    void Render(HDC _hdc);
    void Update();
    void SetEnemyCount();
    Background* GetBackgroundAt(int x, int y);
};

