#pragma once
#include "Projectile.h"
class EnemyBomb :
    public Projectile
{
public:
    EnemyBomb();
    ~EnemyBomb() override;
public:
    void Update() override;
    void Render(HDC _hdc) override;
    void Parry() override;
    void OnPush()override;
public:
    void SetMoveDirection(Vec2 dir)
    {
        _dir = dir;
    }
};

