#include "pch.h"
#include "StageScene.h"
#include "CameraManager.h"
#include "StageManager.h"
#include "BackGround.h"
#include "Enemy.h"

void StageScene::Init()
{
	//CameraManager cameraManager;

	//cameraManager.ShakeConsoleWindow(100, 10);

	for (int i = 0; i < 10; i++)
	{
		Object* obj = new Enemy;
		Object* obj2 = new BackGround;

		obj2->SetPos({rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT});
		obj2->SetSize({ 50, 50 });

		AddObject(obj, LAYER::ENEMY);
		AddObject(obj2, LAYER::BACKGROUND);
	}
}