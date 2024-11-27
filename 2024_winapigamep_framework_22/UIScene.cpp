#include "pch.h"
#include "UIScene.h"
#include "GameCanvas.h"
#include "ResourceManager.h"
#include "Player.h"

UIScene::UIScene() :
	canvas(nullptr)
{
	Object* player = new Player;

	player->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	player->SetName(L"Player");
	AddObject(player, LAYER::PLAYER);
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
	Scene::Update();
	canvas->Update();
}

void UIScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
	canvas->Render(_hdc);
}