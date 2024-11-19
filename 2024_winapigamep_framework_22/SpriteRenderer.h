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
    HBITMAP oldBitmap;
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
    void LookAt(Vec2 dir)
    {
        angle = atan2(dir.y, dir.x);
    }
private:
    float angle;
};

