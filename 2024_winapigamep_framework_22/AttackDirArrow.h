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
    // Object��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render(HDC _hdc) override;
};
