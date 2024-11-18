#include "pch.h"
#include "GameScene.h"
#include "Player.h"

void GameScene::Init()
{
	Object* obj = new Player;
	obj->SetPos({ rand() % SCREEN_WIDTH,
			rand() % SCREEN_HEIGHT });
	obj->SetSize({ 100, 100 });

	AddObject(obj, LAYER::PLAYER);

	/*for (size_t i = 0; i < 100; i++)
	{
	}*/
}
