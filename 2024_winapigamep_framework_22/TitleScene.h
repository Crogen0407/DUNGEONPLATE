#pragma once
#include "Scene.h"
class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();
public:
	void Init() override;
	void Update() override;
};

