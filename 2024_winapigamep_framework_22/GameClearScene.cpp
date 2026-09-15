#include "pch.h"
#include "GameClearScene.h"
#include "GameClearCanvas.h"
#include "ResourceManager.h"

void GameClearScene::Init()
{
	_canvas = new GameClearCanvas;
	AddObject(_canvas, LAYER::UI);

	GET_MANAGER(ResourceManager)->LoadSound(L"Victory_bgm", L"Sound\\Victory_bgm.wav", false);
	GET_MANAGER(ResourceManager)->Play(L"Victory_bgm");
}

void GameClearScene::Release()
{
	Scene::Release();
	GET_MANAGER(ResourceManager)->Stop(SOUND_CHANNEL::BGM);
}

void GameClearScene::Update()
{
	Scene::Update();
}

void GameClearScene::LateUpdate()
{
	Scene::LateUpdate();
}
