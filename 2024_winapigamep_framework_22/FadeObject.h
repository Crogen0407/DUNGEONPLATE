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
public:
    void FadeIn();
    void FadeOut();
private:
	Texture* _screenTransitionTexture = nullptr;
    float _fadeTimer = 0.f;
    float _fadeDuration = 0.5f;
    bool _isFadeIn = false;

    SpriteRenderer* _spriteRenderer = nullptr;
};

