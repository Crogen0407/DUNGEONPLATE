#include "pch.h"
#include "GameOverScene.h"
#include "GameOverCanvas.h"
#include "ResourceManager.h"

void GameOverScene::Init()
{
	_canvas = new GameOverCanvas();
	AddObject(_canvas, LAYER::UI);

	GET_SINGLE(ResourceManager)->LoadSound(L"Retro_bgm", L"Sound\\Retro_bgm.wav", true);
	GET_SINGLE(ResourceManager)->Play(L"Retro_bgm");
}

void GameOverScene::Release()
{
	Scene::Release();
	GET_SINGLE(ResourceManager)->Stop(SOUND_CHANNEL::BGM);
}

void GameOverScene::Update()
{
	Scene::Update();
}

void GameOverScene::LateUpdate()
{
	Scene::LateUpdate();
}

void GameOverScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}
