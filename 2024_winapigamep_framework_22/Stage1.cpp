#include "pch.h"
#include "Stage.h"
#include "Stage1.h"
#include "Stage2.h"
#include "EnemyA.h"
#include "CameraManager.h"
#include "BackGround.h"
#include "StageManager.h"
#include "StageScene.h"
#include "Player.h"

void Stage1::Init()
{
    Object* player = new Player;

    player->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
    player->SetName(L"Player");
    AddObject(player, LAYER::PLAYER);
}

void Stage1::Update()
{
    Stage::Update();

}

void Stage1::Render(HDC _hdc)
{
    Stage::Render(_hdc);
}

void Stage1::DrawScene(StageScene* _stageScene, int x, int y)
{
    BackGround* bg = _stageScene->GetBackGroundAt(x, y);
    if (bg)
    {
        AddObject(bg, LAYER::BACKGROUND); 
    }
}
