#include "pch.h"
#include "BackgroundNull.h"
#include "SpriteRenderer.h"

BackgroundNull::BackgroundNull()
{
	_maxEnemyCount = 0;
	isClear = true;

	_spriteRenderer->SetTexture(L"Background_Empty", L"Texture\\Background_Empty.png");
}

BackgroundNull::~BackgroundNull()
{
}

void BackgroundNull::Update()
{
}

void BackgroundNull::Render(ComPtr<ID2D1RenderTarget> renderTarget)
{
	Object::Render(renderTarget);
}
