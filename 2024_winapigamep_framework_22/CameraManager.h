#pragma once
class CameraManager 
{
public:
    CameraManager(HWND targetWindow = nullptr);
    ~CameraManager();
public:
    void ShakeConsoleWindow(int duration, int power);
private:
    HWND m_targetWindow;
    int m_originalX;
    int m_originalY;
private:
    void SaveOriginalPosition();
};
