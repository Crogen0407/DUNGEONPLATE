#include "pch.h"
#include "StageLoader.h"
#include "EnemySpawner.h"
#include "Scene.h"
#include "GameScene.h"
#include "GameManager.h"
#include "Player.h"
#include "Background.h"
#include "EventManager.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"

Action<int> StageLoader::StageLoadEvent = Action<int>();

StageLoader::StageLoader()
{
	
}

StageLoader::~StageLoader()
{
}

void StageLoader::Init()
{
	_currentStage = nullptr;
	_stageNum = 0;
	_stages.clear();
	RegisterStage<Stage1>();
	//RegisterStage<Stage2>();
	//RegisterStage<Stage3>();

	NextStage();
	_isFirstInit = false;
}

void StageLoader::Update()
{
	if (_currentStage == nullptr)
		return;
}

void StageLoader::TryNextStage()
{
	if (IsClearAllBackground())
	{
		NextStage();
	}
}

void StageLoader::NextStage()
{
	if (_currentStage != nullptr)
		_currentStage->Release();

	if (_stageNum >= _stages.size())
	{
		GET_SINGLE(EventManager)->LoadScene(L"GameClearScene");
	}

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