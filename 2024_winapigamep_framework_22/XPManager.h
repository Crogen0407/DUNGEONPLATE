#pragma once
#include "Action.h"
class XPManager
{
	DECLARE_SINGLE(XPManager);
public:
	const float GetXP() const
	{
		return _xp;
	}
	const int GetLevel() const
	{
		return _level;
	}
	void AddXP(float value)
	{
		_xp += value;
		IncreaseXPEvent.Invoke(_xp/_maxXP);
		if (_xp > _maxXP)
		{
			_maxXP *= 1.5f;
			_xp = 0;
			++_level;
			LevelUpEvent.Invoke(_level);
		}
	}
public:
	Action<float> IncreaseXPEvent;
	Action<int> LevelUpEvent;
public:
	float _xp = 0.f;
	float _maxXP = 10.f;
	int _level;
};

