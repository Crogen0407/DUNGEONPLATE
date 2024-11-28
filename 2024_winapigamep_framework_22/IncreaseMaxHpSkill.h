#pragma once
#include "Skill.h"
class IncreaseMaxHpSkill :
    public Skill
{
public:
    IncreaseMaxHpSkill();
    ~IncreaseMaxHpSkill() override;
public:
    void OnUse(Player* player) override;
};

