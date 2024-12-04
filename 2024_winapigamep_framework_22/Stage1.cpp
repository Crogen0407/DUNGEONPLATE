#include "pch.h"
#include "Stage.h"
#include "Stage1.h"
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

Stage1::Stage1()
{
}

Stage1::~Stage1()
{
}

void Stage1::Init()
{
    AddBackground(0, 0, false);
    AddBackground(0, 1, false);
    AddBackground(0, 2, false);
    AddBackground(1, 0, false);
    AddBackground(1, 1, true);
}

void Stage1::Update()
{
}

void Stage1::Release()
{
}
