#pragma once
#include "Scene.h"

class BackGround;

class StageScene  : 
	public Scene
{
private:
    static const int gridSize = 3;
    BackGround* grid[gridSize][gridSize]; 
public:
    void Init() override;
    void Render(HDC _hdc);
    BackGround* GetBackGroundAt(int x, int y);
};

