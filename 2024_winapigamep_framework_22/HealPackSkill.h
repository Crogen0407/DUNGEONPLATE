#pragma once
#include "Skill.h"
class PlayerHealthCompo;
class HealPackSkill : public Skill
{
public:
    HealPackSkill();
    ~HealPackSkill() override;
public:
    void OnUse(Player* player) override;
    void OnLevelUp(Player* player) override;
private:
    int healAmount = 0;
    PlayerHealthCompo* healthCompo;
};

