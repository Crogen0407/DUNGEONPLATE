#pragma once
#include "Object.h"
class BackGround :
    public Object
{
public:
    BackGround();
    ~BackGround();
public:
    void Update() override;
    void Render(HDC _hdc) override;
};

