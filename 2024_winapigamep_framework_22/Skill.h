#pragma once
#include "Action.h"
class Player;
class Skill
{
public:
	Skill();
	virtual ~Skill();
protected:
	wstring nameText;
	wstring descriptionText;
protected:
	bool enable = false;
	bool isActiveSkill = false;
	int level = 0;
public:
	Action<float> DelayTimeEvent;
	float maxDelayTime = 10;
	float curDelayTime = 0;
public:
	const wstring GetNameText() const
	{
		return nameText;
	}
	const wstring GetDescriptionText() const
	{
		return descriptionText;
	}
	const bool IsActiveSkill() const
	{
		return isActiveSkill;
	}
	const bool GetEnable() const
	{
		return enable;
	}
	void SetEnable(bool value)
	{
		this->enable = value;
	}
	const int GetLevel() const
	{
		return level;
	}
	void SetLevel(int value)
	{
		level = value;
	}
	virtual void Update() {}
public:
	virtual void OnLevelUp(Player* player) {
		++level;
	}
	virtual void OnUse(Player* player) abstract;
};