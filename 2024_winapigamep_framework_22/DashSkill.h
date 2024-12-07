#pragma once
#include "Skill.h"
class Player;
class DashSkill :
    public Skill
{
public:
    DashSkill();
    ~DashSkill() override;
public:
    void OnUse(Player* player) override;
    void OnLevelUp(Player* player) override;
    void Update() override;
    void StopDash();
private:
    void OnDash();
private:
    Player* _player;
    Vec2 _dashDir;
    Vec2 _playerPos;
    Vec2 _prevPos;
    float _originMaxDelayTime = -1;
    float _dashTime = 0.1f;
    float _curDashTime = 0.f;
    const float _dashDistance = 200.f;
    bool _canDash = false;
    bool _isDashing = false;
};

