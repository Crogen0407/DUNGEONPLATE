#include "pch.h"
#include "StageManager.h"
#include "Scene.h"
#include "GameScene.h"
#include "Stage1.h"

void StageManager::Init()
{
	m_pCurrentStage = nullptr;

	RegisterStage(L"Stage1", std::make_shared<Stage1>());


	LoadStage(L"Stage1");
}

void StageManager::Update()
{
	if (m_pCurrentStage = nullptr)
		return;

	m_pCurrentStage->Update();
	m_pCurrentStage->LateUpdate();
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
	if (m_pCurrentStage != nullptr)
	{
		m_pCurrentStage->Release();
		m_pCurrentStage = nullptr;
	}

	auto iter = m_mapStages.find(_stageName);
	if (iter != m_mapStages.end())
	{
		m_pCurrentStage = iter->second;
		m_pCurrentStage->Init();
	}
}
