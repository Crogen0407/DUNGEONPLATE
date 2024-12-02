#include "pch.h"
#include "GameOverScene.h"
#include "GameOverCanvas.h"

void GameOverScene::Init()
{
	_canvas = new GameOverCanvas();
	AddObject(_canvas, LAYER::UI);
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
