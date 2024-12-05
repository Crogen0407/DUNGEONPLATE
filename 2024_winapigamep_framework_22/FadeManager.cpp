#include "pch.h"
#include "FadeManager.h"
#include "InputManager.h"
#include "FadeObject.h"
#include "EventManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "TimeManager.h"

FadeManager::~FadeManager()
{
	//GET_SINGLE(EventManager)->DeleteObject(_fadeObject);
	delete(_fadeObject);
}

void FadeManager::Init()
{
	if(_fadeObject == nullptr)
		_fadeObject = new FadeObject;
}

void FadeManager::Update()
{
	if (_isSceneFading)
	{
		_curTime += fDT;
		if (_curTime > 0.05f * 20.f)
		{
			GET_SINGLE(EventManager)->LoadScene(_sceneName);
			_isSceneFading = false;
			_sceneLoadComplete = false;
			FadeIn();
		}
	}

	_fadeObject->Update();
	_fadeObject->LateUpdate();
}

void FadeManager::Render(HDC hdc)
{
	_fadeObject->Render(hdc);
}

void FadeManager::LoadScene(std::wstring sceneName)
{
	_sceneName = sceneName;
	_isSceneFading = true;
	FadeOut();
}

void FadeManager::FadeIn()
{
	_fadeObject->FadeIn();
}

void FadeManager::FadeOut()
{
	_fadeObject->FadeOut();
}
