#include "pch.h"
#include "Player.h"   
#include "StageScene.h"
#include "StageLoader.h"
#include "Background.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "EnemyC.h"
#include "EnemySpawner.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h" 

void StageScene::Init()
{
    Object* player = new Player;

    player->SetPosition({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
    player->SetName(L"Player");
    AddObject(player, LAYER::PLAYER);

    Object* enemy = new EnemyA;

    enemy->SetPosition({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
    enemy->SetName(L"Enemy");
    AddObject(enemy, LAYER::ENEMY);


    const int cellSizeX = 320;
    const int cellSizeY = 320;
    const int gridSize = 3;
    const int totalGridSize = cellSizeX * gridSize;

    const int startX = (SCREEN_WIDTH - totalGridSize) / 2 + 160;
    const int startY = (SCREEN_HEIGHT - totalGridSize) / 2 + 140;
}

void StageScene::SetEnemyCount()
{
   /* if (m_currentStage == 1)
        StageLoader::GetInstance()->enemyCount = 10;
    else if (m_currentStage == 2)
        StageLoader::GetInstance()->enemyCount = 15;
    else if (m_currentStage == 3)
        StageLoader::GetInstance()->enemyCount = 20;*/
}

Background* StageScene::GetBackgroundAt(int x, int y)
{
    return grid[x][y];
}