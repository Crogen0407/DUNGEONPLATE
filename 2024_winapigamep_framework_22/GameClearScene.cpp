#include "pch.h"
#include "GameClearScene.h"
#include "GameClearCanvas.h"
#include "ResourceManager.h"

void GameClearScene::Init()
{
	_canvas = new GameClearCanvas;
	AddObject(_canvas, LAYER::UI);

	GET_SINGLE(ResourceManager)->LoadSound(L"Victory_bgm", L"Sound\\Victory_bgm.wav", true);
	GET_SINGLE(ResourceManager)->Play(L"Victory_bgm");
}

void GameClearScene::Release()
{
	Scene::Release();
	GET_SINGLE(ResourceManager)->Stop(SOUND_CHANNEL::BGM);
}

void GameClearScene::Update()
{
	Scene::Update();
}

void GameClearScene::LateUpdate()
{
	Scene::LateUpdate();
}

void GameClearScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}
