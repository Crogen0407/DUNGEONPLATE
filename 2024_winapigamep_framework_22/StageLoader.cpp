#include "pch.h"
#include "StageLoader.h"
#include "EnemySpawner.h"
#include "Scene.h"
#include "GameScene.h"
#include "GameManager.h"
#include "Player.h"
#include "Background.h"
#include "FadeManager.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Stage4.h"
#include "Stage5.h"
#include "Stage6.h"
#include "Stage7.h"
#include "Stage8.h"
#include "Stage9.h"
#include "Stage10.h"
#include "Stage11.h"
#include "Stage12.h"

Action<int> StageLoader::StageLoadEvent = Action<int>();
Vec2 StageLoader::mapSize = { 290,290 };

StageLoader::StageLoader() :
	gameScene(nullptr)
{
	StageLoadEvent.Clear();
	LOADSOUND(L"NextLevel", L"Sound\\NextLevel.wav", SOUND_CHANNEL::EFFECT3);
}

StageLoader::~StageLoader()
{
	StageLoadEvent.Clear();
}

void StageLoader::Init()
{
	_currentStage = nullptr;
	_stageNum = 0;
	_stages.clear();
	RegisterStage<Stage1>();
	RegisterStage<Stage2>();
	RegisterStage<Stage3>();
	RegisterStage<Stage4>();
	RegisterStage<Stage5>();
	RegisterStage<Stage6>();
	RegisterStage<Stage7>();
	RegisterStage<Stage8>();
	RegisterStage<Stage9>();
	RegisterStage<Stage10>();
	RegisterStage<Stage11>();
	RegisterStage<Stage12>();

	NextStage();
	_isFirstInit = false;
}

void StageLoader::Update()
{
	if (_isMovingStage)
	{
		_curMoveDelay += fDT;
		if (_curMoveDelay > _moveDelay)
		{
			NextStage();
			PLAY(L"NextLevel");
			_isMovingStage = false;
			_curMoveDelay = 0.f;
			//TIMESCALE = 1.f;
		}
	}
}

void StageLoader::TryNextStage()
{
	if (IsClearAllBackground())
	{
		//TIMESCALE = 0;
		_isMovingStage = true;
	}
}

void StageLoader::NextStage()
{
	if (_stageNum >= _stages.size())
	{
		GET_SINGLE(FadeManager)->LoadScene(L"GameClearScene");
		return;
	}

	if (_currentStage != nullptr)
		_currentStage->Release();

	gameScene->OnNextStageEffect();

	_currentStage = _stages[_stageNum].get();
	_currentStage->Init();

	//플레이어 위치 정해주기
	const Background* bg = _currentStage->GetPlayerArea();
	GET_SINGLE(GameManager)->player->SetPos(bg->GetPos());
	StageLoadEvent.Invoke(_stageNum);
	_stageNum++;
}

bool StageLoader::IsClearAllBackground()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (_currentStage->grid[i][j] == nullptr) continue;
			if (_currentStage->grid[i][j]->isClear == false) return false;
		}
	}

	return true;
}