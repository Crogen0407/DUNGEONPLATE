#pragma once
class Object;
class Background;
class EnemySpawner;
class Stage
{
public:
	Stage();
	virtual ~Stage();
public:
	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Release() abstract;
public:
	Background* AddBackground(int x, int y);
	Background* AddBackground(int x, int y, bool isPlayerArea);
	int GetEnemyCount() const { return _enemyCount; }
protected:
	int _enemyCount;
	Background* grid[3][3];
	bool m_isClear = false;
	EnemySpawner* spawner;
};