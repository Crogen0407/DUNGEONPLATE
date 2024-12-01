#pragma once
#include "Object.h"

class Texture;

class BackGround :
    public Object
{
public:
    BackGround();
    ~BackGround();
public:
    void Update() override;
    void Render(HDC _hdc) override;

private:
    Texture* m_backTexture;
    bool m_isVisible = true; 
};

