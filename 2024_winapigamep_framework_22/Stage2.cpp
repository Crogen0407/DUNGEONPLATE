#include "pch.h"
#include "Stage2.h"
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

Stage2::Stage2()
{
    
}

Stage2::~Stage2()
{
}

void Stage2::Init()
{
    AddBackground(0, 0);
    AddBackground(0, 1);
    AddBackground(0, 2);
    AddBackground(1, 2);
    AddBackground(1, 1, true);
}

