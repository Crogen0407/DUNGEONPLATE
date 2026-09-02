#pragma once
#include "BackGround.h"
class BackgroundNull :
    public Background
{
public:
    BackgroundNull();
    ~BackgroundNull() override;
public:
    void Update() override;
    virtual void Render(ComPtr<ID2D1RenderTarget> renderTarget) override;
};

