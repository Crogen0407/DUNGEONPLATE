#include "pch.h"
#include "CameraManager.h"
#include <cstdlib>
#include <ctime> 
#include <windows.h>
#include <string>
#include <tlhelp32.h>



CameraManager::CameraManager(HWND targetWindow) : m_targetWindow(targetWindow)
{
    if (!m_targetWindow)
        return;

    SaveOriginalPosition();
    srand(static_cast<unsigned int>(time(nullptr)));
}


CameraManager::~CameraManager()
{
}

void CameraManager::ShakeConsoleWindow(int duration, int power) 
{
    if (!m_targetWindow)
        return;

    for (int i = 0; i < duration; ++i) 
    {
        int offsetX = rand() % power - (power / 2);
        int offsetY = rand() % power - (power / 2);
        SetWindowPos(m_targetWindow, nullptr, m_originalX + offsetX, m_originalY + offsetY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        Sleep(10);
    }

    SetWindowPos(m_targetWindow, nullptr, m_originalX, m_originalY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void CameraManager::SaveOriginalPosition() 
{
    if (!m_targetWindow)
        return;

    RECT rect;
    GetWindowRect(m_targetWindow, &rect);
    m_originalX = rect.left;
    m_originalY = rect.top;
}