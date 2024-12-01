#include "pch.h"
#include "FadeManager.h"
#include "InputManager.h"
#include "FadeObject.h"
#include "SceneManager.h"
#include "Scene.h"
#include "TimeManager.h"

void FadeManager::Init()
{
}

void FadeManager::Update()
{
	if (_isSceneFading)
	{
		_curTime += fDT;
		if (_curTime > 0.05f * 19.f)
		{
			GET_SINGLE(SceneManager)->LoadScene(_sceneName);
			_isSceneFading = false;
			_sceneLoadComplete = false;
			cout << "SceneLoad";
			_fadeObject = nullptr;
			FadeIn();
		}
	}

	if (GET_KEYDOWN(KEY_TYPE::I))
	{
		FadeIn();
	}
	if (GET_KEYDOWN(KEY_TYPE::O))
	{
		FadeOut();
	}
	if (GET_KEYDOWN(KEY_TYPE::U))
	{
		LoadScene(L"GameScene");
	}
}

void FadeManager::CreateFadeObject()
{
	cout << "Create";
	_fadeObject = new FadeObject;
	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(_fadeObject, LAYER::SCREENEFFECT);
}

void FadeManager::LoadScene(std::wstring sceneName)
{
	_sceneName = sceneName;
	_isSceneFading = true;
	FadeOut();
}

void FadeManager::FadeIn()
{
	if (_fadeObject == nullptr)
		CreateFadeObject();
	_fadeObject->FadeIn();
}

void FadeManager::FadeOut()
{
	if (_fadeObject == nullptr)
		CreateFadeObject();
	_fadeObject->FadeOut();
}
