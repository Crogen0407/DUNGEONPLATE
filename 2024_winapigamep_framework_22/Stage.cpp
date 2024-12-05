#include "pch.h"
#include "Stage.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Object.h"
#include "Background.h"
#include "EnemySpawner.h"
#include "EventManager.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Release()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == nullptr) continue;
            GET_SINGLE(EventManager)->DeleteObject(grid[i][j]);
        }
    }
}

Background* Stage::AddBackground(int x, int y)
{
    Vec2 size = { SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 };
    Vec2 pos = { size.x * 0.5f + size.x * x, size.y * 0.5f + size.y * y };
    grid[x][y] = new Background;
    grid[x][y]->SetSize(size);
    grid[x][y]->SetPos(pos);
    ADDOBJECT(grid[x][y], LAYER::BACKGROUND);
    return grid[x][y];
}

Background* Stage::AddBackground(int x, int y, bool isPlayerArea)
{
    AddBackground(x, y);
    _playerPos = { x, y };
    grid[x][y]->isPlayerArea = isPlayerArea;
    return grid[x][y];
}

