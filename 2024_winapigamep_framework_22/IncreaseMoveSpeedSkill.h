#pragma once
#include "Skill.h"
class IncreaseMoveSpeedSkill :
    public Skill
{
public:
    IncreaseMoveSpeedSkill();
    ~IncreaseMoveSpeedSkill() override;
private:
    float _playerOriginMoveSpeed = -1;
    float _increasePercent = 0.f;
public:
    void OnUse(Player* player) override;
    void OnLevelUp(Player* player) override;
};

