#pragma once
#include "Component.h"
#include "Action.h"
class HealthCompo :
    public Component
{
public:
    HealthCompo();
    ~HealthCompo() override;
public:
    Action<float> ChangeHpEvent;
    Action<int> DieEvent;
public:
    void SetHp(float hp)
    {
        this->hp = hp;
        ChangeHpEvent.Invoke(hp/maxHp);
    }
    void SetHp(float hp, float maxHp)
    {
        this->maxHp = maxHp;
        SetHp(hp);
    }
    void ApplyDamage(int value);
    void ApplyHeal(int value);
    void OnDie()
    {
        DieEvent.Invoke(NULL);
    }
    const float GetHp() const
    {
        return hp;
    }
private:
    float hp;
    float maxHp;
};

