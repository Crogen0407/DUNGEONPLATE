#include "pch.h"
#include "Background.h"
#include "Collider.h"
#include "EventManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "SpriteRenderer.h"

Background::Background()
{
    AddComponent<SpriteRenderer>();
    _spriteRenderer = GetComponent<SpriteRenderer>();
    _spriteRenderer->isRotatable = false;
    _spriteRenderer->SetTexture(L"Background", L"Texture\\Background.bmp");
}

Background::~Background()
{
}

void Background::Update()
{
}

void Background::Render(HDC _hdc)
{
    ComponentRender(_hdc);
}