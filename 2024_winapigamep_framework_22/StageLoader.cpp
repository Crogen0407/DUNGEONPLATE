#include "pch.h"
#include "StageLoader.h"
#include "Scene.h"
#include "GameScene.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"

StageLoader::StageLoader()
{
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

	_currentStage->Update();

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
}
