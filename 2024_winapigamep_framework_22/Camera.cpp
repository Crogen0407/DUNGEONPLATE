#include "pch.h"
#include "Camera.h"
#include "TimeManager.h"
#include <cstdlib>
#include <ctime> 
#include <windows.h>
#include <string>
#include <tlhelp32.h>

Camera::Camera() : _targetWindow(nullptr)
{
    _targetWindow = GetActiveWindow();

    srand(static_cast<unsigned int>(time(nullptr)));
}


Camera::~Camera()
{
}

void Camera::ShakeConsoleWindow(int duration, int frequency, int amplitude)
{
    SaveOriginalPosition();
    _amplitude = amplitude;
    _frequency = frequency;
    _duration = duration;
    _isShaking = true;
}

void Camera::Update()
{
    if (_isShaking)
    {
        _curDelayTime += fDT;
        for (int i = 0; i < _frequency; i++)
        {
            int offsetX = rand() % _amplitude - (_amplitude / 2);
            int offsetY = rand() % _amplitude - (_amplitude / 2);
            SetWindowPos(_targetWindow, nullptr, 
                m_originalX + offsetX, m_originalY + offsetY,
                0, 0, SWP_NOSIZE | SWP_NOZORDER);
        }
        
        if (_curDelayTime > _duration)
        {
            _curDelayTime = 0.f;
            _duration = 10000.f;
            _isShaking = false;

            SetWindowPos(_targetWindow, nullptr, m_originalX, m_originalY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        }
    }
}

void Camera::SaveOriginalPosition() 
{
    if (!_targetWindow)
        return;

    RECT rect;
    GetWindowRect(_targetWindow, &rect);
    m_originalX = rect.left;
    m_originalY = rect.top;
}