#include "pch.h"
#include "UIScene.h"
#include "GameCanvas.h"
#include "UI.h"
#include "Image.h"
#include "ResourceManager.h"
#include "Text.h"

UIScene::UIScene() :
	canvas(nullptr)
{
	
}

UIScene::~UIScene()
{

}

void UIScene::Init()
{
	canvas = new GameCanvas;
}

void UIScene::Update()
{
	canvas->Update();
}

void UIScene::Render(HDC _hdc)
{
	canvas->Render(_hdc);
}