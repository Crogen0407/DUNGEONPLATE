#include "pch.h"
#include "GameScene.h"
#include "Enemy.h"
void GameScene::Init()
{
	for (size_t i = 0; i < 100; i++)
	{
		Object* obj = new Enemy;
		obj->SetPos({rand() % SCREEN_WIDTH,
				rand() % SCREEN_HEIGHT});
		obj->SetSize({100, 100});
		AddObject(obj, LAYER::ENEMY);
	}
}
