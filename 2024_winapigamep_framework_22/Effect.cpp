#include "pch.h"
#include "Effect.h"
#include "SpriteRenderer.h"
#include "Object.h"

Effect::Effect()
{
	AddComponent<SpriteRenderer>();
	_spriteRenderer = GetComponent<SpriteRenderer>();
}

Effect::~Effect()
{
}

void Effect::OnPop()
{
}

void Effect::OnPush()
{
}

void Effect::Update()
{
}

void Effect::LateUpdate()
{

}

void Effect::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}


void Effect::SetTexture(Texture* texture)
{
	_spriteRenderer->SetTexture(texture);
}
void Effect::SetTexture(wstring name, wstring path)
{
	_spriteRenderer->SetTexture(name, path);
}
void Effect::SetAngle(float angle, bool isDeg = false)
{
	_spriteRenderer->SetAngle(angle, isDeg);
}
void Effect::LookAt(Vec2 dir)
{
	_spriteRenderer->LookAt(dir);
}