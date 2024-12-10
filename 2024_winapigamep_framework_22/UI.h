#pragma once
class Canvas;
class UI
{
protected:
    bool active = true;
    Vec2 _position;
    Vec2 _size;
    Canvas* _owner;
    UI* _parent;
public:
    UI() : 
        _parent(nullptr),
        _owner(nullptr)
    {

    }
    virtual ~UI()
    {
        _parent = nullptr;
    }
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
public:
    void SetOwner(Canvas *canvas)
    {
        _owner = canvas;
    }
    void SetPosAndSize(const Vec2& pos, const Vec2& size)
    {
        this->_position = pos;
        this->_size = size;
    }
public:
    void SetPos(Vec2 pos)
    {
        this->_position = pos;
    }
    void AddPos(const Vec2& pos)
    {
        this->_position += pos;
    }
    void SetSize(Vec2 size)
    {
        this->_size = size;
    }
    Vec2& GetPos()
    {
        return _position;
    }
    Vec2& GetSize()
    {
        return _size;
    }
public:
    void SetParent(UI* parent)
    {
        this->_parent = parent;
    }
    UI* GetParent()
    {
        return this->_parent;
    }
};