#pragma once

enum class UIOPTION
{
    BUTTON = 1,
    IMAGE = 2,
    SLIDER = 4,
    TEXT = 8
};

class UI
{
private:
    Vec2 pos;
    Vec2 size;
public:
    UI();
    virtual ~UI();
public:
    static UI* CreateUI(UIOPTION uiOption);
    static UI* CreateUI(UIOPTION uiOption, Vec2 pos, Vec2 size);
public:
    virtual void LateUpdate() abstract;
    virtual void Render(HDC _hdc) abstract;
public:
    void SetPos(Vec2& pos)
    {
        this->pos = pos;
    }
    void SetSize(Vec2& size)
    {
        this->size = size;
    }
    Vec2& GetPos()
    {
        return pos;
    }
    Vec2& GetSize()
    {
        return size;
    }
};