#pragma once
#include "Enemy.h"
class SkillSystem;
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
	vector<SkillSystem*> _skills;
	SkillSystem* _currentSkill;
};

