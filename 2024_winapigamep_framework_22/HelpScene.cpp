#include "pch.h"
#include "HelpScene.h"
#include "HelpCanvas.h"
#include "ResourceManager.h"

HelpScene::HelpScene()
{
}

HelpScene::~HelpScene()
{
}

void HelpScene::Init()
{
	_canvas = new HelpCanvas;
	AddObject(_canvas, LAYER::UI);

	GET_MANAGER(ResourceManager)->LoadSound(L"Tutorial_bgm", L"Sound\\Tutorial_bgm.wav", true);
	GET_MANAGER(ResourceManager)->Play(L"Tutorial_bgm");
}

void HelpScene::Release()
{
	GET_MANAGER(ResourceManager)->Stop(SOUND_CHANNEL::BGM);
}
