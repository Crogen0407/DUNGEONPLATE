#pragma once
class Player;
#include "Camera.h"
class GameManager
{
	DECLARE_SINGLE(GameManager);
public:
	void Init();
	void Update();
public:
	void ShakeConsoleWindow(int duration, int frequency, int amplitude);
	Player* player = nullptr;
private:
	std::unique_ptr<Camera> _camera;
};