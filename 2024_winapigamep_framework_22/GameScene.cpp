#include "pch.h"
#include "GameScene.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "Player.h"
#include "GameCanvas.h"

void GameScene::Init()
{
	canvas = new GameCanvas;
	Object* player = new Player;

	player->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	player->SetSize({ 50, 50 });
	player->SetName(L"Player");
	AddObject(player, LAYER::PLAYER);

	Object* enemyA = new EnemyA;
	enemyA->SetPos({ rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT });
	enemyA->SetSize({ 50, 50 });
	AddObject(enemyA, LAYER::ENEMY);

	Object* enemyB = new EnemyB;
	enemyB->SetPos({ rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT });
	enemyB->SetSize({ 50, 50 });
	AddObject(enemyB, LAYER::ENEMY);

	/*for (size_t i = 0; i < 100; i++)
	{
	}*/
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
