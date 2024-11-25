#pragma once
#include "Object.h"
class UI;

class Canvas :
    public Object
{
private:
    std::list<UI*> children;
public:
    Canvas();
    virtual ~Canvas() override;
public:
    void Update() override;
    void LateUpdate() override;
    void Render(HDC _hdc) override;
public:
    void AddUI(UI* newUI)
    {
        children.push_back(newUI);
    }
};

