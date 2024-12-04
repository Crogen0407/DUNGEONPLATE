#pragma once
#include <queue>
class Stage;
class StageLoader
{
public:
	StageLoader();
	~StageLoader();
public:
	static StageLoader* GetInstance()
	{
		static StageLoader instance;
		return &instance;
	}
public:
	void Init();
	void Update();
public:
	//static Background* grid[3][3];
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
	int enemyCount;
	//std::shared_ptr<Stage> GetCurrentStage() { return m_pCurrentStage; }
private:
	std::queue<std::unique_ptr<Stage>> _stageQueue;
	std::unique_ptr<Stage> _currentStage;
	bool m_isClear = false;
};