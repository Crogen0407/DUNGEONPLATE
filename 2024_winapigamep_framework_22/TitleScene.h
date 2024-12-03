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
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;
private:
	Canvas* _canvas;
};

