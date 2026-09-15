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
#include "Managers.h"

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

	//BGM Àç»ý
	GET_MANAGER(ResourceManager)->LoadSound(L"Title_bgm", L"Sound\\Title_bgm.wav", true);
	GET_MANAGER(ResourceManager)->Play(L"Title_bgm");
}

void TitleScene::Release()
{
	Scene::Release();
	GET_MANAGER(ResourceManager)->Stop(SOUND_CHANNEL::BGM);
}