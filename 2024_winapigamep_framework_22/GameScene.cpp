#include "pch.h"
#include "GameScene.h"
#include "EnemyA.h"

void GameScene::Init()
{
	Object* obj = new EnemyA;

	obj->SetPos({ rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT });
	obj->SetSize({ 100, 100 });

	AddObject(obj, LAYER::ENEMY);

	/*for (size_t i = 0; i < 100; i++)
	{
	}*/
}
