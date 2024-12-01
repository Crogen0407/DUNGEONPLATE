#include "pch.h"
#include "FadeObject.h"
#include "SpriteRenderer.h"
#include "Animator.h"
#include "ResourceManager.h"
#include "Texture.h"

FadeObject::FadeObject()
{
	AddComponent<SpriteRenderer>();
	AddComponent<Animator>();

	_spriteRenderer = GetComponent<SpriteRenderer>();
	_animator = GetComponent<Animator>();

	_fadeOutTexture = LOADTEXTURE(L"ScreenTransition_FadeOut", L"Texture\\Effect\\ScreenTransition_FadeOut.bmp");
	_fadeInTexture = LOADTEXTURE(L"ScreenTransition_FadeIn", L"Texture\\Effect\\ScreenTransition_FadeIn.bmp");
	_blackTexture = LOADTEXTURE(L"OnePoint", L"Texture\\OnePoint.bmp");
}

FadeObject::~FadeObject()
{
}

void FadeObject::Update()
{

}

void FadeObject::LateUpdate()
{
	Object::LateUpdate();
}

void FadeObject::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}
