#include "pch.h"
#include "StageScene.h"
#include "CameraManager.h"
#include "StageManager.h"
#include "BackGround.h"
#include "EnemyA.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Player.h"

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

    cout << "왜 안그려져";

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

void StageScene::Render(HDC _hdc)
{
    Stage1* stage1 = new Stage1;

    stage1->DrawScene(this, 1, 1, _hdc);
    stage1->DrawScene(this, 1, 2, _hdc);
}

BackGround* StageScene::GetBackGroundAt(int x, int y)
{
    return grid[x][y];
}