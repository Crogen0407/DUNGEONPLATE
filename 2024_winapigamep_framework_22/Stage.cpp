#include "pch.h"
#include "Stage.h"
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
            GET_MANAGER(EventManager)->DeleteObject(grid[i][j]);
        }
    }
}


