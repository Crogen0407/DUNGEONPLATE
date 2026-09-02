#pragma once
#include "BackGround.h"
#include "Object.h"
#include "SceneManager.h"
#include "StageLoader.h"
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
	virtual void Initialize() abstract;
	void Release();
public:
	template<typename T>
	T* AddBackground(int x, int y)
	{
		Vec2 size = StageLoader::mapSize;

		int xStart = (SCREEN_WIDTH	- size.x * 3) / 2 + (size.x/2);
		int yStart = (SCREEN_HEIGHT - size.y * 3) / 2 + (size.y/2);

		Vec2 pos = 
		{ 
			xStart + size.x * x,
			yStart + size.y * y
		};
		grid[x][y] = new T;
		grid[x][y]->owner = this;
		grid[x][y]->SetSize(size);
		grid[x][y]->SetPosition(pos);
		ADDOBJECT(grid[x][y], LAYER::BACKGROUND);
		return static_cast<T*>(grid[x][y]);
	}
	template<typename T>
	T* AddBackground(float x, float y, bool isPlayerArea)
	{
		AddBackground<T>(x, y);
		_playerPos = { x, y };
		grid[(int)x][(int)y]->isPlayerArea = isPlayerArea;
		return static_cast<T*>(grid[(int)x][(int)y]);
	}
	unsigned __int8 GetEnemyCount() const { return _enemyCount; }
	const Background* GetPlayerArea() const
	{
		return grid[(int)_playerPos.x][(int)_playerPos.y];
	}
public:
	Background* grid[3][3];
protected:
	unsigned __int8 _enemyCount;
	Vec2 _playerPos;
	bool m_isClear = false;
};