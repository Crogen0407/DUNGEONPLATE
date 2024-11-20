#include "pch.h"
#include "Stage1.h"
#include "Enemy.h"
#include "CameraManager.h"
#include "BackGround.h"

void Stage1::Init()
{
	CameraManager cameraManager;

	cameraManager.ShakeConsoleWindow(100, 10);

	for (int i = 0; i < 100; i++)
	{
		Object* obj = new Enemy;
		Object* obj2 = new BackGround;

		obj->SetPos({ rand() % SCREEN_WIDTH,
				rand() % SCREEN_HEIGHT });
		obj->SetSize({ 100, 100 });

		AddObject(obj, LAYER::ENEMY);
		AddObject(obj2, LAYER::BACKGROUND);
	}
}
