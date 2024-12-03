#include "pch.h"
#include "HelpScene.h"
#include "HelpCanvas.h"

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
}
