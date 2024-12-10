#pragma once
#include <queue>
#include "Action.h"
#include "Stage.h"
class EnemySpawner;
class Background;
class GameScene;
class StageLoader
{
public:
	StageLoader();
	~StageLoader();
public:
	void Init();
	void Update();
public:
	template<typename T>
	void RegisterStage()
	{
		std::unique_ptr<T> stage = std::make_unique<T>();
		stage->stageLoader = this;
		_stages.push_back(static_cast<std::unique_ptr<Stage>>(std::move(stage)));
	}
	void TryNextStage();
	void NextStage();
	bool IsClearAllBackground();
public:
	static Action<int> StageLoadEvent;
	int enemyCount;
	std::vector<std::unique_ptr<Stage>> _stages = {};
private:
	Stage* _currentStage = nullptr;
	int _stageNum = 0;
	bool _isFirstInit = true;
	bool _isMovingStage = false;
	const float _moveDelay = 0.5f;
	float _curMoveDelay = 0.f;
public:
	GameScene* gameScene;
	static Vec2 mapSize;
};