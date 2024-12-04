#pragma once
#include "Object.h"
class SpriteRenderer;
class Texture;

class Background :
    public Object
{
public:
    Background();
    ~Background();
public:
    void Update() override;
    void Render(HDC _hdc) override;
public:
    bool isPlayerArea = false;
private:
    SpriteRenderer* _spriteRenderer;
};

