#include "pch.h"
#include "StageScene.h"
#include "CameraManager.h"
#include "StageManager.h"
#include "BackGround.h"
#include "EnemyA.h"
#include "Stage1.h"
#include "Stage2.h"

void StageScene::Init()
{
    const int cellSizeX = 190;
    const int cellSizeY = 240;
    const int gridSize = 3;
    const int totalGridSize = cellSizeX * gridSize;

    const int startX = (SCREEN_WIDTH - totalGridSize) / 2 + 95;
    const int startY = (SCREEN_HEIGHT - totalGridSize) / 2 - 15;

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            grid[i][j] = new BackGround;

            grid[i][j]->SetPos({ startX + i * cellSizeX, startY + j * cellSizeY });
            grid[i][j]->SetSize({ cellSizeX, cellSizeY });

            AddObject(grid[i][j], LAYER::BACKGROUND);
        }
    }
}

BackGround* StageScene::GetBackGroundAt(int x, int y)
{
    if (x >= 0 && x < gridSize && y >= 0 && y < gridSize)
    {
        return grid[x][y];
    }

    return nullptr;
}
