#pragma once
#include "IManager.h"
class Skill;
class Player;
enum class ESkillType
{
	//Skills
	DashSkill,
	HealPack,
	IncreaseAttackSpeed,
	IncreaseMoveSpeed,
	FireBall,
	//Items
	HealItem,
	LAST
};

class SkillManager : public IManager
{
	~SkillManager();
public:
	Player* player = nullptr;
private:
	map<ESkillType, Skill*> skills;
public:
	void Init() override;
	void Update() override;
	void Release() override;
public:
	const vector<Skill*> GetRandomSkills();
	Skill* GetSkill(const ESkillType& type)
	{
		return skills[type];
	}
	void AddSkill(ESkillType type, Skill* skill);
	void LevelUpSkill(ESkillType type);
};

