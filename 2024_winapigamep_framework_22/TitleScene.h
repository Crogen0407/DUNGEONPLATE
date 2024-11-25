#pragma once
#include "Scene.h"
class TitleScene : public Scene
{
	TitleScene();
	~TitleScene();
public:
	void Init() override;
	void Update() override;
};

