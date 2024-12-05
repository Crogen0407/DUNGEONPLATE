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
	m_pCurrentScene = nullptr;

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
	if (m_pCurrentScene == nullptr)
		return;
	m_pCurrentScene->Update();
	m_pCurrentScene->LateUpdate();
}

void SceneManager::Render(HDC _hdc)
{
	if (m_pCurrentScene == nullptr)
		return;
	m_pCurrentScene->Render(_hdc);
}

void SceneManager::RegisterScene(const wstring& _sceneName, std::shared_ptr<Scene> _scene)
{
	if (_sceneName.empty() || _scene == nullptr)
		return;
	m_mapScenes.insert(m_mapScenes.end(), {_sceneName, _scene});
}

void SceneManager::LoadScene(const wstring& _sceneName)
{
	// ¾ÀÀÌ ÀÖÀ¸¸é
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->Release();
		m_pCurrentScene = nullptr;
	}
	auto iter = m_mapScenes.find(_sceneName);
	if (iter != m_mapScenes.end())
	{
		m_pCurrentScene = iter->second;
		m_pCurrentScene->Init();
	}
	GET_SINGLE(PoolManager)->Init(m_pCurrentScene.get());
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
