#include "pch.h"
#include "Stage1.h"
#include "Stage2.h"
#include "EnemyA.h"
#include "CameraManager.h"
#include "BackGround.h"
#include "StageManager.h"
#include "StageScene.h"

void Stage1::Init()
{

}

void Stage1::DrawScene(StageScene* _stageScene, int x, int y)
{
    BackGround* bg = _stageScene->GetBackGroundAt(x, y);
    if (bg)
    {
        AddObject(bg, LAYER::BACKGROUND); 
    }
}
