#pragma once
#include "Skill.h"
class DashSkill :
    public Skill
{
public:
    DashSkill();
    ~DashSkill() override;
public:
    void OnUse(Player* player) override;
};

