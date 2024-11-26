#include "pch.h"
#include "CameraManager.h"
#include <cstdlib>
#include <ctime> 

CameraManager::CameraManager() 
{
    m_consoleWindow = GetConsoleWindow();
    if (!m_consoleWindow) 
        return;
    
    SaveOriginalPosition();
    srand(static_cast<unsigned int>(time(nullptr)));
}

CameraManager::~CameraManager() 
{
}

void CameraManager::ShakeConsoleWindow
(int duration, int power) 
{
    if (!m_consoleWindow) 
        return;

    for (int i = 0; i < duration; ++i) 
    {
        int offsetX = rand() % power - (power / 2);
        int offsetY = rand() % power - (power / 2);
        SetWindowPos(m_consoleWindow, nullptr, m_originalX + offsetX, m_originalY + offsetY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        Sleep(10);
    }

    SetWindowPos(m_consoleWindow, nullptr, m_originalX, m_originalY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void CameraManager::SaveOriginalPosition() 
{
    if (!m_consoleWindow) 
        return;

    RECT rect;
    GetWindowRect(m_consoleWindow, &rect);
    m_originalX = rect.left;
    m_originalY = rect.top;
}
