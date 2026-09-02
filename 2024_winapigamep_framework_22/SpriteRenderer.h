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
public:
    void LateUpdate() override;
    void Render(ComPtr<ID2D1RenderTarget> renderTarget) override;
public:
    void SetTexture(std::wstring name, std::wstring path);
    void SetTexture(Texture* texture);
    void SetAngle(float angle, bool isDeg = false)
    {
        if (isDeg) this->angle = angle;
        else this->angle = angle * Rad2Deg;
    }
    void LookAt(const Vec2& dir)
    {
        this->angle = (std::atan2(dir.y, dir.x)+PI/2.f) * Rad2Deg;
    }
public:
    bool enable = true;
private:
    float angle = 0.f;
};

