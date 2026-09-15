#pragma once
#include "IManager.h"
#include "Camera.h"
class CameraManager : public IManager
{
public:
	void Init() override;
	void Update() override;
	void ShakeConsoleWindow(int duration, int frequency, int amplitude);
private:
	std::unique_ptr<Camera> _camera;
};

