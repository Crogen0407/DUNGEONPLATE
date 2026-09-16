#pragma once
#include "Item.h"
class HealItem :
    public Item
{
public:
    HealItem();
    ~HealItem();

public:
    void OnLevelUp(Player* player) override;
    void OnUse(Player* player) override;
};