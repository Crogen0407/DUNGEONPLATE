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

    cout << "¹Ö¹Ö";
}

void Stage1::Update()
{
    Stage::Update();

}

void Stage1::Render(StageScene* stageScene, HDC _hdc)
{
    Stage::Render(_hdc);
    
    DrawScene(stageScene, 1, 1, _hdc);
}

void Stage1::DrawScene(StageScene* stageScene, int x, int y, HDC _hdc)
{
    BackGround* bg = stageScene->GetBackGroundAt(x, y);
    if (bg)
    {
        bg->Render(_hdc);
    }
}
