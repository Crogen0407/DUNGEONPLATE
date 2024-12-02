#include "pch.h"
#include "Player.h"   
#include "StageScene.h"
#include "CameraManager.h"
#include "StageManager.h"
#include "BackGround.h"
#include "EnemyA.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h" 

void StageScene::Init()
{
    Object* player = new Player;

    player->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
    player->SetName(L"Player");
    AddObject(player, LAYER::PLAYER);

    Object* enemy = new EnemyA;

    enemy->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
    enemy->SetName(L"Enemy");
    AddObject(enemy, LAYER::ENEMY);


    const int cellSizeX = 195;
    const int cellSizeY = 195;
    const int gridSize = 3;
    const int totalGridSize = cellSizeX * gridSize;

    const int startX = (SCREEN_WIDTH - totalGridSize) / 2 + 97;
    const int startY = (SCREEN_HEIGHT - totalGridSize) / 2 + 30;

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            grid[i][j] = new BackGround;

            grid[i][j]->SetPos({ startX + i * cellSizeX, startY + j * cellSizeY });
            grid[i][j]->SetSize({ cellSizeX, cellSizeY });
        }
    }
}

void StageScene::Update()
{
    //frameCount++; 

    if (enemyCount <= 0) 
    {
        StageManager::GetInstance()->SetClear(true);
        m_currentStage++;
        //frameCount = 0;
        SetEnemyCount();
        cout << "다음 스테이지로 이동!";
    }

    Scene::Update();
}

void StageScene::SetEnemyCount()
{
    if (m_currentStage == 1)
        enemyCount = 10;

    /*if(적이 죽으면)
        enemyCount--;*/
}

void StageScene::Render(HDC _hdc)
{
    Stage1* stage1 = new Stage1;
    Stage2* stage2 = new Stage2;
    Stage3* stage3 = new Stage3;

    auto stageManager = StageManager::GetInstance();

    if (stageManager->IsClear())
    {
        if (m_currentStage == 1) {
            stage1->Render(this, _hdc);
        }
        else if (m_currentStage == 2) {
            stage2->Render(this, _hdc);
        }
        else if (m_currentStage == 3) {
            stage3->Render(this, _hdc);
        }
    }
    else
    {
        if (!stage1) stage1 = new Stage1();
        stage1->Render(this, _hdc);
    }
}

BackGround* StageScene::GetBackGroundAt(int x, int y)
{
    return grid[x][y];
}