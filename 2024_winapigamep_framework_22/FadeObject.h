#pragma once
#include "Object.h"
class SpriteRenderer;
class Animator;
class Texture;
class FadeObject :
    public Object
{
public:
    FadeObject();
    ~FadeObject();
public:
    void Update() override; 
    void LateUpdate() override;
    void Render(HDC _hdc) override;
public:
    void FadeIn();
    void FadeOut();
private:
    Texture* _fadeOutTexture;
    Texture* _fadeInTexture;
    Texture* _blackTexture;
    SpriteRenderer* _spriteRenderer;
    Animator* _animator;
};

