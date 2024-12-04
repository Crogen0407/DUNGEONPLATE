#include "pch.h"
#include "Stage3.h"
#include "Stage1.h"
#include "Stage2.h"
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

void Stage3::Init()
{
    Object* backGround = new BackGround;

    AddObject(backGround, LAYER::BACKGROUND);

    EnemySpawner* spawner = new EnemySpawner;

    spawner->SpawnEnemy({ SCREEN_WIDTH / 2.5f, SCREEN_HEIGHT / 2.5f }, EnemyType::EnemyA);
}

void Stage3::Update()
{
	Stage::Update();
}

void Stage3::Render(GameScene* _gameScene, HDC _hdc)
{
    Stage::Render(_hdc);
    DrawScene(_gameScene, 2, 1, _hdc);
}

void Stage3::DrawScene(GameScene* _gameScene, int x, int y, HDC _hdc)
{
    BackGround* bg = _gameScene->GetBackGroundAt(x, y);
    if (bg)
    {
        bg->Render(_hdc);
    }
}
