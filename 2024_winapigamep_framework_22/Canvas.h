#pragma once
#include "Object.h"
#include <memory>

class UI;
class Canvas :
    public Object
{
private:
    std::list<std::unique_ptr<UI>> children;
public:
    Canvas();
    virtual ~Canvas() override;
public:
    void Update() override;
    void LateUpdate() override;
    void Render(HDC _hdc) override;
public:
    template<typename T>
    T* CreateUI() {
        static_assert(std::is_base_of<UI, T>::value, "T must derive from UI");

        auto newInstance = std::make_unique<T>();
        newInstance->SetOwner(this);
        T* rawPointer = newInstance.get();
        children.push_back(std::move(newInstance));
        return rawPointer;
    }
    
    template<typename T>
    T* CreateUI(const Vec2& pos, const Vec2& size) {
        T* newInstance = CreateUI<T>();
        newInstance->SetPosAndSize(pos, size);

        return newInstance;
    }
};

