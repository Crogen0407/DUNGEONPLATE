#pragma once
#include "Managers.h"

class IManager {
public:
    virtual void Init() abstract;
    virtual void Update() { /* Empty */ }
    virtual void Render(ComPtr<ID2D1BitmapRenderTarget> renderTarget) { /* Empty */ }
    virtual void Release() { /* Empty */ }
};
