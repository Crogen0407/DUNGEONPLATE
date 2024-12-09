#pragma once
#include "Enemy.h"
class Pattern;
class Texture;
class Boss : public Enemy
{
public:
	Boss();
	~Boss() override;
public:
	void Update() override;
	void Render(HDC _hdc) override;
private:
	Texture* texture;
	float _prevSkillTime;
	float _skillCoolTime = 2;
	vector<Pattern*> _skills;
	Pattern* _currentSkill;
	float _prevDash;
	float _dashDelay = 2.f;
};

