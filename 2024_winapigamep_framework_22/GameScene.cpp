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
#include "StageLoader.h"
#include "GDISelector.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	if (_stageLoader != nullptr)
		delete(_stageLoader);
}

void GameScene::Init()
{
	Object* player = new Player;
	player->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	player->SetName(L"Player");
	AddObject(player, LAYER::PLAYER);
	
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::PROJECTILE);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::ENEMY, LAYER::PROJECTILE);

	_stageLoader = new StageLoader;
	_stageLoader->Init();

	_gameCanvas = new GameCanvas;
	_skillCanvas = new SkillCanvas;

	AddObject(_gameCanvas, LAYER::UI);
	AddObject(_skillCanvas, LAYER::UI);

	EnemySpawner* spawner = new EnemySpawner();
	spawner->SpawnEnemy({ 200,200 }, EnemyType::EnemyA);

	//delete spawner;

	//GET_SINGLE(ResourceManager)->LoadSound(L"Retro_bgm", L"Sound\\Retro_bgm.wav", true);
	GET_SINGLE(ResourceManager)->Play(L"Retro_bgm");
}

void GameScene::Release()
{
	Scene::Release();
	delete(_stageLoader);
	_stageLoader = nullptr;
	GET_SINGLE(ResourceManager)->Stop(SOUND_CHANNEL::BGM);
}

void GameScene::Update()
{
	_stageLoader->Update();
	Scene::Update();
}

void GameScene::Render(HDC hdc)
{
	GDISelector::GDISelector(hdc, RGB(15, 56, 15));
	RECT_RENDER(hdc, SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f,
		SCREEN_WIDTH, SCREEN_HEIGHT);

	Scene::Render(hdc);
}

void GameScene::SetEnemyCount()
{
}
