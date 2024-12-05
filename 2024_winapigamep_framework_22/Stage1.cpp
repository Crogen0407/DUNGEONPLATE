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
    AddBackground(0, 0, true);
    AddBackground(0, 1);
    AddBackground(0, 2);
    AddBackground(1, 0);
    AddBackground(1, 1);
}
