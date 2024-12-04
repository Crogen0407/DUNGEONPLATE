#include "pch.h"
#include "Stage.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Object.h"
#include "Background.h"
#include "EnemySpawner.h"

Stage::Stage()
{
    spawner = new EnemySpawner;
}

Stage::~Stage()
{
    delete spawner;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            delete(grid[i][j]);
}

Background* Stage::AddBackground(int x, int y)
{
    Vec2 size = { SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 };
    Vec2 pos = { size.x * 0.5f + size.x * x, size.y * 0.5f + size.y * y };
    Background* bg = new Background;
    bg->SetSize(size);
    bg->SetPos(pos);
    ADDOBJECT(bg, LAYER::BACKGROUND);
    return bg;
}

Background* Stage::AddBackground(int x, int y, bool isPlayerArea)
{
    Background* bg = AddBackground(x, y);
    bg->isPlayerArea = isPlayerArea;
    return bg;
}

