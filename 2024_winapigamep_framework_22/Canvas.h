#pragma once
#include "Object.h"
enum class UIOPTION
{
    BUTTON = 1,
    IMAGE = 2,
    SLIDER = 4,
    TEXT = 8
};
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
    UI* CreateUI(UIOPTION uiOption);
    UI* CreateUI(UIOPTION uiOption, Vec2 pos, Vec2 size);
public:
    void AddUI(UI* newUI)
    {
        children.push_back(newUI);
    }
};

