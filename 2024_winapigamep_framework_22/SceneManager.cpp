#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "UIScene.h"
#include "GameOverScene.h"
#include "GameClearScene.h"
#include "HelpScene.h"
#include "Object.h"
#include "PoolManager.h"
#include "EventManager.h"

void SceneManager::Init()
{
	_currentScene = nullptr;

	// ¾À µî·Ï
	RegisterScene(L"TitleScene",std::make_shared<TitleScene>());
	RegisterScene(L"GameScene",std::make_shared<GameScene>());
	RegisterScene(L"UIScene",std::make_shared<UIScene>());
	RegisterScene(L"GameOverScene",std::make_shared<GameOverScene>());
	RegisterScene(L"GameClearScene",std::make_shared<GameClearScene>());
	RegisterScene(L"HelpScene",std::make_shared<HelpScene>());

	// ¾À ·Îµå
	LoadScene(L"TitleScene");
}

void SceneManager::Update()
{
	if (_currentScene == nullptr)
		return;
	_currentScene->Update();
	_currentScene->LateUpdate();
}

void SceneManager::Render(ComPtr<ID2D1BitmapRenderTarget> renderTarget)
{
	if (_currentScene == nullptr)
		return;
	_currentScene->Render(renderTarget);
}

void SceneManager::RegisterScene(const wstring& _sceneName, std::shared_ptr<Scene> _scene)
{
	if (_sceneName.empty() || _scene == nullptr)
		return;
	_scenes.insert(_scenes.end(), {_sceneName, _scene});
}

void SceneManager::LoadScene(const wstring& _sceneName)
{
	// ¾ÀÀÌ ÀÖÀ¸¸é
	if (_currentScene != nullptr)
	{
		_currentScene->Release();
		_currentScene = nullptr;
	}
	auto iter = _scenes.find(_sceneName);
	if (iter != _scenes.end())
	{
		_currentScene = iter->second;
		_currentScene->Init();
	}
	GET_SINGLE(PoolManager)->Init(_currentScene.get());
}

Object* SceneManager::FindObject(std::wstring name, LAYER layer)
{
	vector<Object*> objects = GetCurrentScene()->GetLayerObjects(layer);

	for (Object* obj : objects)
	{
		if (obj->GetName() == name) {
			return obj;
		}
	}

	return nullptr;
}
