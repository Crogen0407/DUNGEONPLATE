#pragma once
class Canvas;
class UI
{
protected:
    Vec2 pos;
    Vec2 size;
    Canvas* owner;
public:
    UI();
    virtual ~UI();
public:
    virtual void LateUpdate() abstract;
    virtual void Render(HDC _hdc) abstract;
public:
    void SetOwner(Canvas *canvas)
    {
        owner = canvas;
    }
    void SetPos(Vec2 pos)
    {
        this->pos = pos;
    }
    void SetSize(Vec2 size)
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