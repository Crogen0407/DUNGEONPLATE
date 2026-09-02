#pragma once
#include "Scene.h"
class Canvas;
class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();
public:
	void Init() override;
	void Release() override;
private:
	Canvas* _canvas;
};

