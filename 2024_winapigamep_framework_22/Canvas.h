#pragma once
#include "Object.h"
#include <memory>

class UI;
class Canvas :
    public Object
{
private:
    std::list<UI*> children;

public:
    bool enable = true;

public:
    Canvas();
    virtual ~Canvas() override;

public:
    void Update() override;
    void LateUpdate() override;
    void Render(ComPtr<ID2D1RenderTarget> renderTarget) override;

public:
    template<typename T>
    T* CreateUI() 
    {
        static_assert(std::is_base_of<UI, T>::value, "T must derive from UI");

        auto newInstance = new T;
        newInstance->SetOwner(this);
        children.push_back(newInstance);
        return newInstance;
    }
    
    template<typename T>
    T* CreateUI(const Vec2& pos, const Vec2& size) 
    {
        T* newInstance = CreateUI<T>();
        newInstance->SetPositionAndSize(pos, size);

        return newInstance;
    }
};

