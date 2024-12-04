#include "pch.h"
#include "Stage3.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "EnemyC.h"
#include "EnemySpawner.h"
#include "CameraManager.h"
#include "Background.h"
#include "StageScene.h"
#include "GameScene.h"
#include "Player.h"
#include "Object.h"

Stage3::Stage3()
{
    
}

Stage3::~Stage3()
{
}

void Stage3::Init()
{
    AddBackground(0, 0, false);
    AddBackground(0, 1, false);
    AddBackground(0, 2, false);
    AddBackground(1, 0, false);
    AddBackground(1, 1, true);

    spawner->SpawnEnemy({ SCREEN_WIDTH / 2.5f, SCREEN_HEIGHT / 2.5f }, EnemyType::EnemyA);
}

void Stage3::Update()
{
}

void Stage3::Release()
{
}
