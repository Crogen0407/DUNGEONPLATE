#include "pch.h"
#include "CameraManager.h"

void CameraManager::Init()
{
}

void CameraManager::Update()
{
	if (_camera == nullptr) return;
	_camera->Update();
}

void CameraManager::ShakeConsoleWindow(int duration, int frequency, int amplitude)
{
	if (_camera == nullptr)
		_camera = std::make_unique<Camera>();
	_camera->ShakeConsoleWindow(duration, frequency, amplitude);
}