#pragma once
class Canvas;
class UI
{
protected:
    bool active = true;
    Vec2 pos;
    Vec2 size;
    Canvas* owner;
public:
    UI() = default;
    virtual ~UI() = default;
public:
    virtual void LateUpdate() abstract;
    virtual void Render(HDC _hdc) abstract;
public:
    const bool GetActive() const
    {
        return active;
    }
    void SetActive(const bool& active)
    {
        this->active = active;
    }
    void SetOwner(Canvas *canvas)
    {
        owner = canvas;
    }
    void SetPosAndSize(const Vec2& pos, const Vec2& size)
    {
        this->pos = pos;
        this->size = size;
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