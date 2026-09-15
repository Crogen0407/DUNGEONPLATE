#include "pch.h"
#include "Managers.h"
#include "IManager.h"
#include "CollisionManager.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "SkillManager.h"
#include "SceneManager.h"
#include "FadeManager.h"
#include "CameraManager.h"
#include "EventManager.h"

void Managers::Init()
{
	_managerVec.clear();

	Add<CollisionManager>();
	Add<TimeManager>();
	Add<InputManager>();
	Add<ResourceManager>();
	Add<SkillManager>();
	Add<SceneManager>();
	Add<FadeManager>();
	Add<CameraManager>();
	Add<EventManager>();

	for (auto manager : _managerVec)
	{
		manager->Init();
	}
}

void Managers::Update()
{
	for (auto manager : _managerVec)
	{
		manager->Update();
	}
}

void Managers::Render(ComPtr<ID2D1BitmapRenderTarget> renderTarget)
{
	for (auto manager : _managerVec)
	{
		manager->Render(renderTarget);
	}
}

void Managers::Release()
{
	for (auto manager : _managerVec)
	{
		manager->Release();
	}
}