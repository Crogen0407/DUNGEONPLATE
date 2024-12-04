#include "pch.h"
#include "StageLoader.h"
#include "EnemySpawner.h"
#include "Scene.h"
#include "GameScene.h"
#include "GameManager.h"
#include "Player.h"
#include "Background.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"

StageLoader::StageLoader()
{
	_enemySpawner = std::make_unique<EnemySpawner>();
}

StageLoader::~StageLoader()
{
}

void StageLoader::Init()
{
	RegisterStage<Stage1>();
	RegisterStage<Stage2>();
	RegisterStage<Stage3>();

	NextStage();
}

void StageLoader::Update()
{
	if (_currentStage = nullptr)
		return;

	if (m_isClear)
	{
		NextStage();
		m_isClear = false;
	}
}

void StageLoader::NextStage()
{
	if (_currentStage != nullptr)
		_currentStage->Release();

	_currentStage = std::move(_stageQueue.front());
	_stageQueue.pop();

	_currentStage->Init();

	//플레이어 위치 정해주기
	const Background* bg = _currentStage->GetPlayerArea();
	GET_SINGLE(GameManager)->player->SetPos(bg->GetPos());

}