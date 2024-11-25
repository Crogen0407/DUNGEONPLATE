#pragma once
#include "Component.h"
class HealthCompo :
    public Component
{
public:
    HealthCompo();
    ~HealthCompo() override;
public:
    //여기에 실행 이벤트
public:
    void SetHp(float hp)
    {
        this->hp = hp;
    }
    void SetHp(float hp, float maxHp)
    {
        this->hp = hp;
        this->maxHp = maxHp;
    }
    void ApplyDamage(int value);
    void ApplyHeal(int value);
    const float GetHp() const
    {
        return hp;
    }
private:
    float hp;
    float maxHp;
};

