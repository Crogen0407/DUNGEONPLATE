#pragma once
class CameraManager 
{
public:
    CameraManager();
    ~CameraManager();
public:
    void ShakeConsoleWindow(int duration, int power);
private:
    HWND m_consoleWindow;
    int m_originalX;
    int m_originalY;
private:
    void SaveOriginalPosition();
};
