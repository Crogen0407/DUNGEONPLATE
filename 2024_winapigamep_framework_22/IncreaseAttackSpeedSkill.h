#pragma once
#include "Skill.h"
class IncreaseAttackSpeedSkill :
    public Skill
{
public:
    IncreaseAttackSpeedSkill();
    ~IncreaseAttackSpeedSkill() override;
public:
    void OnUse(Player* player) override;
    void OnLevelUp(Player* player) override;
private:
    float _originParryCoolTime = -1;
};

