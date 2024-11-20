#include "pch.h"
#include "TitleScene.h"
#include "Object.h"
#include "Player.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "ResourceManager.h"
#include "SimpleBtnObject.h"
#include "AttackDirArrow.h"

void TitleScene::Init()
{
	//Object* pTitleStartBtn = new SimpleBtnObject;
	//pTitleStartBtn->SetPos({ SCREEN_WIDTH / 2.f, SCREEN_HEIGHT*0.6f });
	//pTitleStartBtn->SetName(L"TitleStartBtn");
	//pTitleStartBtn->SetSize({300.f, 50.f});
	//AddObject(pTitleStartBtn, LAYER::DEFAULT);

	//pObj->SetPos({ SCREEN_WIDTH / 2.f,150.f });
	//pObj->SetSize({ 100.f,100.f });
	//pObj->SetName(L"Enemy");
	//AddObject(pObj, LAYER::ENEMY);

	Object* pPlayer = new Player;
	pPlayer->SetPos({ SCREEN_WIDTH / 2.f,500.f });
	pPlayer->SetSize({ 100.f,100.f });
	AddObject(pPlayer, LAYER::PLAYER);

	AttackDirArrow* pArrow = new AttackDirArrow;
	pArrow->SetPos({ pPlayer->GetPos().x, pPlayer->GetPos().y - 10 });
	pArrow->SetSize({ 100.f,100.f });
	pArrow->SetParent(pPlayer);
	AddObject(pArrow, LAYER::UI);

	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PROJECTILE, LAYER::ENEMY);
	//GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::ENEMY);
	GET_SINGLE(ResourceManager)->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
	GET_SINGLE(ResourceManager)->Play(L"BGM");
}

void TitleScene::Update()
{
	Scene::Update();
	
}
