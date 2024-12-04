#include "pch.h"
#include "GameScene.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "EnemyC.h"
#include "Player.h"
#include "Boss.h"
#include "GameCanvas.h"
#include "SkillCanvas.h"
#include "CollisionManager.h"
#include "EnemySpawner.h"
#include "Stage.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "BackGround.h"
#include "StageManager.h"

void GameScene::Init()
{
	Object* player = new Player;

	player->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	player->SetName(L"Player");
	AddObject(player, LAYER::PLAYER);

	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::PROJECTILE);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::ENEMY, LAYER::PROJECTILE);
	GET_SINGLE(CollisionManager)->CheckLayer(LAYER::PLAYER, LAYER::BACKGROUND);

	_gameCanvas = new GameCanvas;
	_skillCanvas = new SkillCanvas;

	const int cellSizeX = 320;
	const int cellSizeY = 320;
	const int gridSize = 3;
	const int totalGridSize = cellSizeX * gridSize;

	const int startX = (SCREEN_WIDTH - totalGridSize) / 2 + 160;
	const int startY = (SCREEN_HEIGHT - totalGridSize) / 2 + 140;

	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			_grid[i][j] = new BackGround;

			_grid[i][j]->SetPos({ startX + i * cellSizeX, startY + j * cellSizeY });
			_grid[i][j]->SetSize({ cellSizeX, cellSizeY });
		}
	}

	isInitialized = true;
	AddObject(_gameCanvas, LAYER::UI);
	AddObject(_skillCanvas, LAYER::UI);
}

void GameScene::Update()
{
	//if (StageManager::GetInstance()->enemyCount <= 0)
	//{
	//	StageManager::GetInstance()->SetClear(true);
	//	m_currentStage++;
	//	SetEnemyCount();
	//	cout << m_currentStage;
	//	cout << "´ÙÀ½ ½ºÅ×ÀÌÁö·Î ÀÌµ¿!" << endl;
	//}

	//frameCount++;

	if (frameCount >= maxFrame)
	{
		StageManager::GetInstance()->SetClear(true);
		m_currentStage++;
		frameCount = 0;
		cout << "³Ñ¾î°¬´Ù.¾ÆÀ×¾ÆÀ× ²ó²ó ³ª´Â ¹Ì¼Ò³à°¡ µÇ°íÇÂ ±èµ¿·üÀÎ°Å½Ã¿Í¿ä~";
	}

	Scene::Update();
}

void GameScene::Render(HDC hdc)
{
	if (!isInitialized) return;

	auto stageManager = StageManager::GetInstance();

	if (stageManager->IsClear())
	{
		if (m_currentStage == 2)
			stage2->Render(this, hdc);
		else if (m_currentStage == 3)
			stage3->Render(this, hdc);
	}
	else
	{
		if (!stage1) 
			stage1 = new Stage1();
		stage1->Init();
		stage1->Render(this, hdc);
	}

	Scene::Render(hdc);
}

void GameScene::SetEnemyCount()
{
	if (m_currentStage == 1)
		StageManager::GetInstance()->enemyCount = 10;
	else if (m_currentStage == 2)
		StageManager::GetInstance()->enemyCount = 15;
	else if (m_currentStage == 3)
		StageManager::GetInstance()->enemyCount = 20;
}

BackGround* GameScene::GetBackGroundAt(int x, int y)
{
	return _grid[x][y];
}
