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
};

