#pragma once
class Skill;
class Player;
enum class ESkillType
{
	DashSkill,
	HealPack,
	IncreaseAttackSpeed,
	IncreaseMaxHp,
	IncreaseMoveSpeed,
	LAST
};

class SkillManager
{
	DECLARE_SINGLE(SkillManager);
public:
	Player* player;
private:
	map<ESkillType, Skill*> skills;
public:
	void Init();
	void Update();
public:
	const vector<Skill*> GetRendomSkills();
	void AddSkill(ESkillType type, Skill* skill);
	void LevelUpSkill(ESkillType type);
public:
};

