#pragma once
#include "BackGround.h"
#include "Object.h"
#include "SceneManager.h"
#include "Scene.h"

class Object;
class StageLoader;
class Stage
{
public:
	StageLoader* stageLoader;
public:
	Stage();
	virtual ~Stage();
public:
	virtual void Init() abstract;
	void Release();
public:
	template<typename T>
	T* AddBackground(int x, int y)
	{
		Vec2 size = { SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3 };
		Vec2 pos = { size.x * 0.5f + size.x * x, size.y * 0.5f + size.y * y };
		grid[x][y] = new T;
		grid[x][y]->owner = this;
		grid[x][y]->SetSize(size);
		grid[x][y]->SetPos(pos);
		ADDOBJECT(grid[x][y], LAYER::BACKGROUND);
		return static_cast<T*>(grid[x][y]);
	}
	template<typename T>
	T* AddBackground(int x, int y, bool isPlayerArea)
	{
		AddBackground<T>(x, y);
		_playerPos = { x, y };
		grid[x][y]->isPlayerArea = isPlayerArea;
		return static_cast<T*>(grid[x][y]);
	}
	int GetEnemyCount() const { return _enemyCount; }
	const Background* GetPlayerArea() const
	{
		return grid[(int)_playerPos.x][(int)_playerPos.y];
	}
public:
	Background* grid[3][3];
protected:
	int _enemyCount;
	Vec2 _playerPos;
	bool m_isClear = false;
};