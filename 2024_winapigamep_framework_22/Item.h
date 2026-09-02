#pragma once
#include "Skill.h"
class Item :
    public Skill
{
public:
    Item();
    virtual ~Item() override;
public:
    virtual void OnUse(Player* player) abstract override;
};

