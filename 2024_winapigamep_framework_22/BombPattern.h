#pragma once
#include "Pattern.h"
class Player;
class BombPattern :
    public Pattern
{
public:
    BombPattern();
    ~BombPattern() override;
public:
    void Update() override;
    void UseSkill() override;
private:
    Player* _player;
    float _delayTime = 1.f;
    float _curDelayTime = 0.f;
    const int _bombMaxCount = 3;
    int _curBombMaxCount = 0;
};

