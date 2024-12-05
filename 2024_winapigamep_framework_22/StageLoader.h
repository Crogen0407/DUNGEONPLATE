#pragma once
#include <queue>
#include "Action.h"

class Stage;
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
		_stageQueue.push(std::move(stage));
	}
	void NextStage();
public:
	void SetClear(bool isClear) { m_isClear = isClear; }
	bool IsClear() const { return m_isClear; }
public:
	static Action<int> StageLoadEvent;
	int enemyCount;
	std::queue<std::unique_ptr<Stage>> _stageQueue;
	std::unique_ptr<Stage> _currentStage;
	bool m_isClear = false;
private:
	int _stageNum = 0;
	std::unique_ptr<EnemySpawner> _enemySpawner;
};