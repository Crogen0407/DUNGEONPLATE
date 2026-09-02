#pragma once
#include "BackGround.h"
class BackgroundG : public Background
{
public:
	BackgroundG();
	~BackgroundG() override;
public:
	void Update() override;
private:
	float _currentTime = 0;
	float _spawnDelayTime = 10.f;
};

