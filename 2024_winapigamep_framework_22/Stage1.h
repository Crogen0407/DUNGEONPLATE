#pragma once
#include "Stage.h"

class StageScene;

class Stage1 : public Stage
{
	virtual void Init() override;
	void Update();
	void Render(HDC _hdc);
public:
	void DrawScene(StageScene* stageScene, int x, int y);
};

