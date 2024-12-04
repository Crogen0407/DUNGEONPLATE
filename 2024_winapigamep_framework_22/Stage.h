#pragma once
class Object;
class Background;
class Stage
{
public:
	Stage();
	virtual ~Stage();
public:
	virtual void Init() abstract;
	void Release();
public:
	Background* AddBackground(int x, int y);
	Background* AddBackground(int x, int y, bool isPlayerArea);
	int GetEnemyCount() const { return _enemyCount; }
	const Background* GetPlayerArea() const
	{
		return grid[(int)_playerPos.x][(int)_playerPos.y];
	}
protected:
	int _enemyCount;
	Background* grid[3][3];
	Vec2 _playerPos;
	bool m_isClear = false;
};