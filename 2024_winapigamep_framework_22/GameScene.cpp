#include "pch.h"
#include "GameScene.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "EnemyC.h"
#include "Player.h"
#include "Boss.h"
#include "GameCanvas.h"
#include "SkillCanvas.h"
#include "CollisionManager.h"
#include "EnemySpawner.h"
#include "ResourceManager.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	delete(_spawner);
}

void GameScene::Init()
{
	Object* player = new Player;

	player->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	player->SetName(L"Player");
	AddObject(player, LAYER::PLAYER);

	Object* obj = new EnemyC;
	obj->SetPos({ rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT });
	AddObject(obj, LAYER::ENEMY);
	
	_spawner = new EnemySpawner();
	_spawner->SpawnEnemy({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100 }, EnemyType::EnemyA);
	/*_spawner->SpawnEnemy({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100 }, EnemyType::EnemyB);
	_spawner->SpawnEnemy({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100 }, EnemyType::EnemyC);
	_spawner->SpawnEnemy({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 500 }, EnemyType::EnemyD);
	_spawner->SpawnEnemy({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100 }, EnemyType::Boss);*/
	
	/*Object* enemyb = new EnemyB;
	enemyb->SetPos({ rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT });
	AddObject(enemyb, LAYER::ENEMY);*/

	/*Object* boss = new Boss;
	boss->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 100 });
	AddObject(boss, LAYER::ENEMY);*/

	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::PROJECTILE);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::ENEMY, LAYER::PROJECTILE);
	/*for (size_t i = 0; i < 100; i++)
	{
	}*/

	_gameCanvas = new GameCanvas;
	_skillCanvas = new SkillCanvas;

	AddObject(_gameCanvas, LAYER::UI);
	AddObject(_skillCanvas, LAYER::UI);

	GET_SINGLE(ResourceManager)->LoadSound(L"Retro_bgm", L"Sound\\Retro_bgm.wav", true);
	GET_SINGLE(ResourceManager)->Play(L"Retro_bgm");
}

void GameScene::Release()
{
	Scene::Release();
	GET_SINGLE(ResourceManager)->Stop(SOUND_CHANNEL::BGM);
}

void GameScene::Update()
{
	Scene::Update();
}

void GameScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
