#pragma once
#include "Object.h"
class AttackDirArrow : public Object
{
public:
    AttackDirArrow();
    ~AttackDirArrow() override;
private:
    Object* parent;
public:
    void SetParent(Object* parent);
public:
    // Object을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render(HDC _hdc) override;
};
