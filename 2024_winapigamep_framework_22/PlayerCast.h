#pragma once
#include "Object.h"
class Collider;
class PlayerCast :
    public Object
{
public:
    PlayerCast();
    PlayerCast(float startAngle);
    ~PlayerCast() override;
public:
    void Update() override;
    void LateUpdate() override;
    void EnterCollision(Collider* _other);
    void StayCollision(Collider* _other);
    void ExitCollision(Collider* _other);
    const bool IsCast() const
    {
        return _isCast;
    }
public:
    void SetMoveDir(Vec2 dir);
    Collider* other;
private:
    float _startAngle = 0.f;
    Vec2 _dir;
    float _distance = 10.f;
    Collider* _collider;
    bool _isCast = true;
};

