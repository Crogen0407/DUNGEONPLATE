#pragma once
#include "Effect.h"

enum class EFireBallModeType
{
    FireBall_S,
    FireBall_M,
    FireBall_L
};

class FireBallEffect :
    public Effect
{
public:
    FireBallEffect();
    ~FireBallEffect() override;
public:
    void OnPop() override;
    void OnPush() override;

    void Update() override;
    void Render(HDC _hdc) override;
    void EnterCollision(Collider* _other) override;
    
    void SetDir(const Vec2& dir);
    void SetMode(const EFireBallModeType& mode);
private:
    Vec2 _moveDir;
    const float _speed = 400.f;
};

