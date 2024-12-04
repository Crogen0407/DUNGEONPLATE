#include "pch.h"
#include "Stage.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "EnemyC.h"
#include "EnemySpawner.h"
#include "CameraManager.h"
#include "BackGround.h"
#include "StageManager.h"
#include "StageScene.h"
#include "GameScene.h"
#include "Player.h"
#include "Object.h"

void Stage1::Init()
{
    Object* backGround = new BackGround;

    AddObject(backGround, LAYER::BACKGROUND);

    EnemySpawner* spawner = new EnemySpawner;

    spawner->SpawnEnemy({SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2}, EnemyType::EnemyA);
}

void Stage1::Update()
{
    Stage::Update();
}

void Stage1::Render(GameScene* _gameScene, HDC _hdc)
{
    Stage::Render(_hdc);

    DrawScene(_gameScene, 0, 0, _hdc);
    DrawScene(_gameScene, 0, 1, _hdc);
    DrawScene(_gameScene, 0, 2, _hdc);
    DrawScene(_gameScene, 1, 0, _hdc);
    DrawScene(_gameScene, 1, 1, _hdc);
}

void Stage1::DrawScene(GameScene* _gameScene, int x, int y, HDC _hdc)
{
    BackGround* bg = _gameScene->GetBackGroundAt(x, y);

    if (bg)
    {
        bg->Render(_hdc);
    }
}