#pragma once
class Skill;
class Player;
enum class ESkillType
{
	DashSkill,
	HealPack,
	IncreaseAttackSpeed,
	IncreaseMoveSpeed,
	FireBall,
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
	Skill* GetSkill(const ESkillType& type)
	{
		return skills[type];
	}
	void AddSkill(ESkillType type, Skill* skill);
	void LevelUpSkill(ESkillType type);
public:
};

