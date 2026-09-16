#include "pch.h"
#include "UIScene.h"
#include "GameCanvas.h"
#include "SkillSelectCanvas.h"
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

	player->SetPosition({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	player->SetName(L"Player");
	AddObject(player, LAYER::PLAYER);

	gameCanvas = new GameCanvas;
	skillSelectCanvas = new SkillSelectCanvas;
	AddObject(gameCanvas, LAYER::UI);
	AddObject(skillSelectCanvas, LAYER::UI);
}

void UIScene::Update()
{
	Scene::Update();

	if (GET_KEYDOWN(KEY_TYPE::P))
		static_cast<SkillSelectCanvas*>(skillSelectCanvas)->ShowSlots();
}
