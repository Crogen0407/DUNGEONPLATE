#include "pch.h"
#include "Stage3.h"
#include "Stage1.h"
#include "Stage2.h"
#include "EnemyA.h"
#include "CameraManager.h"
#include "BackGround.h"
#include "StageManager.h"
#include "StageScene.h"

void Stage3::Init()
{
    const int cellSize = 20;
    const int gridWidth = SCREEN_WIDTH / cellSize;
    const int gridHeight = SCREEN_HEIGHT / cellSize;

    for (int i = 0; i < gridWidth; i++)
    {
        for (int j = 0; j < gridHeight; j++)
        {
            if (i == 1 || i == gridWidth - 1 || j == 3 || j == 41)
            {
                Object* obj2 = new BackGround;

                obj2->SetPos({ i * cellSize, j * cellSize });
                obj2->SetSize({ cellSize, cellSize });

                AddObject(obj2, LAYER::BACKGROUND);
            }
        }
    }
}

void Stage3::Update()
{
	Stage::Update();
}

void Stage3::Render(StageScene* stageScene, HDC _hdc)
{
    Stage::Render(_hdc);
    DrawScene(stageScene, 2, 1,
        _hdc);
}

void Stage3::DrawScene(StageScene* stageScene, int x, int y, HDC _hdc)
{
    BackGround* bg = stageScene->GetBackGroundAt(x, y);
    if (bg)
    {
        stageScene->AddObject(bg, LAYER::BACKGROUND);
        bg->Render(_hdc);
    }
}
