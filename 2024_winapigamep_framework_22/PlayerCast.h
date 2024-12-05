#pragma once
#include "Object.h"
class Collider;
class PlayerCast :
    public Object
{
public:
    PlayerCast();
    ~PlayerCast() override;
public:
    void Update() override;
    void LateUpdate() override;
    void Render(HDC _hdc) override;
    void EnterCollision(Collider* _other);
    void StayCollision(Collider* _other);
    void ExitCollision(Collider* _other);
    const bool IsCast() const
    {
        return _isCast;
    }
public:
    void SetMoveDir(Vec2 dir);
private:
    Vec2 _dir;
    float _distance = 30.f;
    Collider* _collider;
    bool _isCast = true;
};

