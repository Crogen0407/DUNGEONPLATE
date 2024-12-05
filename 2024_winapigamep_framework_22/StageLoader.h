#pragma once
#include <queue>
#include "Action.h"
#include "Stage.h"
class EnemySpawner;
class Background;
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
	void SetClear(bool isClear) { m_isClear = isClear; }
	bool IsClear() const { return m_isClear; }
public:
	static Action<int> StageLoadEvent;
	int enemyCount;
	std::vector<std::unique_ptr<Stage>> _stages = {};
	bool m_isClear = false;
private:
	Stage* _currentStage = nullptr;
	int _stageNum = 0;
	std::unique_ptr<EnemySpawner> _enemySpawner;
};