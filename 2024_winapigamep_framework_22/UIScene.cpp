#include "pch.h"
#include "UIScene.h"
#include "GameCanvas.h"
#include "SkillCanvas.h"
#include "ResourceManager.h"
#include "Player.h"
#include "InputManager.h"

UIScene::UIScene() :
	gameCanvas(nullptr)
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

	gameCanvas = new GameCanvas;
	skillCanvas = new SkillCanvas;
	AddObject(gameCanvas, LAYER::UI);
	AddObject(skillCanvas, LAYER::UI);
}

void UIScene::Update()
{
	Scene::Update();

	if (GET_KEYDOWN(KEY_TYPE::P))
		static_cast<SkillCanvas*>(skillCanvas)->ShowSlots();
}

void UIScene::Render(HDC _hdc)
{
	Scene::Render(_hdc);
}