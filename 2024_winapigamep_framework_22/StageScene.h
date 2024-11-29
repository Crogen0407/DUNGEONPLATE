#pragma once
#include "Scene.h"

class BackGround;

class StageScene  : 
	public Scene
{
private:
    static const int gridSize = 3;
    BackGround* grid[gridSize][gridSize];  // 3x3 °ÝÀÚ

public:
    void Init() override;
    BackGround* GetBackGroundAt(int x, int y);
};

