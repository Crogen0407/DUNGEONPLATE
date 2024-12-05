#pragma once
#include "Component.h"
#include "ResourceManager.h"

class Texture;
class SpriteRenderer :
    public Component
{
public:
    SpriteRenderer();
    ~SpriteRenderer() override;
private:
    Texture* texture;
    HDC memDC;
    HBITMAP hBmap;
    HBRUSH brush;
public:
    void LateUpdate() override;
    void Render(HDC _hdc) override;
public:
    void SetTexture(std::wstring name, std::wstring path);
    void SetTexture(Texture* texture);
    void SetAngle(float angle, bool isDeg = false)
    {
        if (isDeg)
        {
            this->angle = angle * Deg2Rad;
            angle -= PI / 2;
        }
        else
            this->angle = angle;
    }
    void LookAt(const Vec2& dir)
    {
        this->angle = std::atan2(dir.y, dir.x);
    }
public:
    bool enable = true;
    bool isRotatable = true;
private:
    float angle;
};

