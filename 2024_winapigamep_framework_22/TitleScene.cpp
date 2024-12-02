#include "pch.h"
#include "TitleScene.h"
#include "Object.h"
#include "Player.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "ResourceManager.h"
#include "TitleCanvas.h"


TitleScene::TitleScene()
{
	
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	_canvas = new TitleCanvas;
	AddObject(_canvas, LAYER::UI);

	//GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::ENEMY);
	////GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::ENEMY);
	//GET_SINGLE(ResourceManager)->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	//GET_SINGLE(ResourceManager)->Play(L"BGM");
}

void TitleScene::Update()
{
	Scene::Update();
}

void TitleScene::LateUpdate()
{
	Scene::LateUpdate();
}

void TitleScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
