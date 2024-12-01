#pragma once
#include "Skill.h"
#include "FireBallEffect.h"

class SpriteRenderer;
class Player;
class FireBallSkill :
    public Skill
{
public:
    FireBallSkill();
    ~FireBallSkill() override;
public:
    void OnUse(Player* player) override;
    void OnLevelUp(Player* player) override;
    void Update() override;
private:
    void Fire(Player* player, const EFireBallModeType& fireBallModeType, const int& count);
};

