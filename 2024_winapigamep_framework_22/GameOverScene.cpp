#include "pch.h"
#include "GameOverScene.h"
#include "GameOverCanvas.h"
#include "ResourceManager.h"

void GameOverScene::Init()
{
	_canvas = new GameOverCanvas();
	AddObject(_canvas, LAYER::UI);

	GET_MANAGER(ResourceManager)->LoadSound(L"Gameover_bgm", L"Sound\\Gameover_bgm.wav", false);
	GET_MANAGER(ResourceManager)->Play(L"Gameover_bgm");
}

void GameOverScene::Release()
{
	Scene::Release();
}

void GameOverScene::Update()
{
	Scene::Update();
}

void GameOverScene::LateUpdate()
{
	Scene::LateUpdate();
}
