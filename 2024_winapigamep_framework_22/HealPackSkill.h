#pragma once
#include "Skill.h"
class PlayerHealthCompo;
class HealPackSkill : public Skill
{
public:
    HealPackSkill();
    ~HealPackSkill();

public:
    void OnUse(Player* player) override;
    void OnLevelUp(Player* player) override;

private:
    unsigned __int8 healAmount = 0;
    PlayerHealthCompo* healthCompo;
};

