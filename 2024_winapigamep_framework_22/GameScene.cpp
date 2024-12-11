#include "pch.h"
#include "GameScene.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "EnemyC.h"
#include "Player.h"
#include "Boss.h"
#include "GameCanvas.h"
#include "SkillCanvas.h"
#include "PauseCanvas.h"
#include "CollisionManager.h"
#include "ResourceManager.h"
#include "StageLoader.h"
#include "GDISelector.h"
#include "SkillManager.h"
#include "TimeManager.h"
#include "InputManager.h"

//#include "InputManager.h"
//#include "XPManager.h"

GameScene::GameScene() :
	_stageLoader(nullptr)
{
	_stageLoader = std::make_unique<StageLoader>();
	_stageLoader->gameScene = this;
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	Object* player = new Player;
	player->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	player->SetName(L"Player");
	AddObject(player, LAYER::PLAYER);

	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::PROJECTILE);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYERCAST, LAYER::BACKGROUND);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::ENEMY, LAYER::PROJECTILE);

	_gameCanvas = new GameCanvas;
	_skillCanvas = new SkillCanvas;
	_pauseCanvas = new PauseCanvas;

	AddObject(_gameCanvas, LAYER::UI);
	AddObject(_skillCanvas, LAYER::UI);
	AddObject(_pauseCanvas, LAYER::UI);
	_pauseCanvas->SetActive(false);
	TIME = 0.f;
	_stageLoader->Init();

	GET_SINGLE(ResourceManager)->LoadSound(L"Fight_bgm", L"Sound\\Fight_bgm.wav", true);
	GET_SINGLE(ResourceManager)->Play(L"Fight_bgm");
}

void GameScene::Release()
{
	Scene::Release();
	GET_SINGLE(ResourceManager)->Stop(SOUND_CHANNEL::BGM);
	GET_SINGLE(SkillManager)->Release();
}

void GameScene::Update()
{
	if (GET_KEYDOWN(KEY_TYPE::ESC))
	{
		_pauseCanvas->SetActive(!_pauseCanvas->GetActive());
		TIMESCALE = !_pauseCanvas->GetActive();
	}

	_stageLoader->Update();
	Scene::Update();
	//if (GET_KEYDOWN(KEY_TYPE::NUM_1))
	//{
	//	ADDXP(5);
	//}
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

void GameScene::OnNextStageEffect()
{
	_gameCanvas->isMoveToNextStage = true;
}
