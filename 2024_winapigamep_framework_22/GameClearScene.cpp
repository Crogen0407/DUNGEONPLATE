#include "pch.h"
#include "GameClearScene.h"
#include "GameClearCanvas.h"

void GameClearScene::Init()
{
	_canvas = new GameClearCanvas;
	AddObject(_canvas, LAYER::UI);
}

void GameClearScene::Update()
{
}

void GameClearScene::LateUpdate()
{
}

void GameClearScene::Render(HDC _hdc)
{
}
