#pragma once
class Camera 
{
public:
    Camera();
    ~Camera();
public:
    void ShakeConsoleWindow(int duration, int frequency, int amplitude);
    void Update();
private:
    HWND _targetWindow;
    int m_originalX;
    int m_originalY;
    bool _isShaking = false;
    float _duration = 10000.f;
    float _curDelayTime = 0.f;
private:
    int _amplitude;
    int _frequency;
private:
    void SaveOriginalPosition();
};
