#pragma once
#include "Effect.h"
class SpriteRenderer;
class Collider;
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
    Collider* _collider;
    SpriteRenderer* _spriteRenderer;
    Vec2 _moveDir;
    const float _speed = 400.f;
    int _damage = 15.f;
};

