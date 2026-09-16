#pragma once
#include "Skill.h"
class Item :
    public Skill
{
public:
    Item() { level = -1; }
    ~Item() { /* Emtpy */ }

public:
    virtual void OnUse(Player* player) abstract override;
};

