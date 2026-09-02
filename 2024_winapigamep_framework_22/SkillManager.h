#pragma once
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

class SkillManager
{
	DECLARE_SINGLE(SkillManager);
	~SkillManager();
public:
	Player* player;
private:
	map<ESkillType, Skill*> skills;
public:
	void Init();
	void Update();
	void Release();
public:
	const vector<Skill*> GetRandomSkills();
	Skill* GetSkill(const ESkillType& type)
	{
		return skills[type];
	}
	void AddSkill(ESkillType type, Skill* skill);
	void LevelUpSkill(ESkillType type);
public:
};

