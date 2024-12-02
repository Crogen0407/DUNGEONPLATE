#include "pch.h"
#include "GameScene.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "EnemyC.h"
#include "Player.h"
#include "Boss.h"
#include "GameCanvas.h"
#include "CollisionManager.h"
#include "EnemySpawner.h"

void GameScene::Init()
{
	Object* player = new Player;

	player->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	player->SetName(L"Player");
	AddObject(player, LAYER::PLAYER);

	Object* obj = new EnemyC;
	obj->SetPos({ rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT });
	AddObject(obj, LAYER::ENEMY);
	
	EnemySpawner* spawner = new EnemySpawner();
	spawner->SpawnEnemy({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100 }, EnemyType::EnemyA);
	spawner->SpawnEnemy({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100 }, EnemyType::EnemyB);
	spawner->SpawnEnemy({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100 }, EnemyType::EnemyC);
	
	/*Object* enemyb = new EnemyB;
	enemyb->SetPos({ rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT });
	AddObject(enemyb, LAYER::ENEMY);*/

	Object* boss = new Boss;
	boss->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100 });
	AddObject(boss, LAYER::ENEMY);

	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::PROJECTILE);
	/*for (size_t i = 0; i < 100; i++)
	{
	}*/

	canvas = new GameCanvas;
}

void GameScene::Update()
{
	Scene::Update();
	canvas->Update();
}

void GameScene::Render(HDC hdc)
{
	Scene::Render(hdc);
	canvas->Render(hdc);
}
