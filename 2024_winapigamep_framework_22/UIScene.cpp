#include "pch.h"
#include "UIScene.h"
#include "GameCanvas.h"
#include "ResourceManager.h"
#include "Player.h"

UIScene::UIScene() :
	canvas(nullptr)
{
	
}

UIScene::~UIScene()
{

}

void UIScene::Init()
{
	Object* player = new Player;

	player->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	player->SetName(L"Player");
	AddObject(player, LAYER::PLAYER);

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