#pragma once
class Skill;
class Player;
enum class ESkillType
{
	FIREBALL,
	LAST
};

class SkillManager
{
	DECLARE_SINGLE(SkillManager);
private:
	Player* player;
	map<ESkillType, Skill*> skills;
public:
	void Init();
	void Update();
public:
	void AddSkill(ESkillType type, Skill& skill);
	void LevelUpSkill(ESkillType type);
public:
};

