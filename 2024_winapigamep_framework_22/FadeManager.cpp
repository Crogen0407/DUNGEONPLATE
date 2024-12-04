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
	delete(_fadeObject);
}

void FadeManager::Init()
{
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
			_fadeObject = nullptr;
			FadeIn();
		}
	}

	if (_fadeObject == nullptr) return;
	_fadeObject->Update();
	_fadeObject->LateUpdate();
}

void FadeManager::Render(HDC hdc)
{
	if (_fadeObject == nullptr) return;
	_fadeObject->Render(hdc);
}

void FadeManager::CreateFadeObject()
{
	_fadeObject = new FadeObject;
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
