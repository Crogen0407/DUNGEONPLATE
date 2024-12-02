#include "pch.h"
#include "StageManager.h"
#include "Scene.h"
#include "GameScene.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"

void StageManager::Init()
{
	m_pCurrentStage = nullptr;

	RegisterStage(L"Stage1", std::make_shared<Stage1>());
	RegisterStage(L"Stage2", std::make_shared<Stage2>());
	RegisterStage(L"Stage3", std::make_shared<Stage3>());
}

void StageManager::Update()
{
	if (m_pCurrentStage = nullptr)
		return;

	m_pCurrentStage->Update();
	m_pCurrentStage->LateUpdate();

	if (m_isClear)
	{
		NextStage();
		m_isClear = false;
	}
}

void StageManager::Render(HDC _hdc)
{
	if (m_pCurrentStage == nullptr)
		return;

	m_pCurrentStage->Release();
}

void StageManager::RegisterStage(const wstring& _stageName, std::shared_ptr<Stage> _stage)
{
	if (_stageName.empty() || _stage == nullptr)
		return;

	m_mapStages.insert(m_mapStages.end(), { _stageName, _stage });
}

void StageManager::LoadStage(const wstring& _stageName)
{
	auto iter = m_mapStages.find(_stageName);

	if (iter != m_mapStages.end())
	{
		if (m_pCurrentStage)
		{
			m_pCurrentStage->Release();
		}

		m_pCurrentStage = iter->second;
		m_pCurrentStage->Init();
	}
}

void StageManager::NextStage()
{
	static vector<wstring> stageOrder = { L"Stage1", L"Stage2", L"Stage3"};
	static int currentStageIndex = 0;

	currentStageIndex++;
	if (currentStageIndex < stageOrder.size())
	{
		LoadStage(stageOrder[currentStageIndex]);
	}
	else
	{
		cout << "모든 스테이지를 클리어했습니다!" << endl;
	}
}
