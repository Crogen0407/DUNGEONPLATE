#include "pch.h"
#include "GameManager.h"

void GameManager::Init()
{
}

void GameManager::Update()
{
	if (_camera == nullptr) return;

	_camera->Update();
}

void GameManager::ShakeConsoleWindow(int duration, int frequency, int amplitude)
{
	if (_camera == nullptr)
		_camera = std::make_unique<Camera>();
	_camera->ShakeConsoleWindow(duration, frequency, amplitude);
}
