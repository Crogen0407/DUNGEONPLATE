#include "pch.h"
#include "BackGround.h"
#include "Collider.h"
#include "EventManager.h"
#include "ResourceManager.h"
#include "Texture.h"

BackGround::BackGround()
{
    m_backTexture = LOADTEXTURE(L"Background", L"Texture\\Background.bmp");
}

BackGround::~BackGround()
{
}

void BackGround::Update()
{
}

void BackGround::Render(HDC _hdc)
{
    Vec2 vPos = GetPos();
    Vec2 vSize = GetSize();

    RECT_RENDER(_hdc, vPos.x, vPos.y, vSize.x, vSize.y);

    if (m_backTexture && m_backTexture->GetTexDC())
    {
        TransparentBlt(_hdc,
            vPos.x - vSize.x / 2, vPos.y - vSize.y / 2,
            vSize.x, vSize.y,
            m_backTexture->GetTexDC(), 0, 0,
            m_backTexture->GetWidth(), m_backTexture->GetHeight(),
            RGB(255, 0, 255));
    }

    ComponentRender(_hdc);
}