#include "pch.h"
#include "Text.h"
#include "ResourceManager.h"
#include "Canvas.h"
#include "Core.h"

Text::Text() :
	_style(DWRITE_FONT_STYLE_NORMAL),
	_color(D2D1::ColorF(0x0f380f)),
	_weight(DWRITE_FONT_WEIGHT_NORMAL),
	_stretch(DWRITE_FONT_STRETCH_NORMAL)
{
	GET_SINGLE(Core)->GetRenderTarget()->CreateSolidColorBrush(_color, _brush.GetAddressOf());
}

Text::~Text()
{
}

void Text::LateUpdate()
{
}

void Text::Render(ComPtr<ID2D1RenderTarget> renderTarget)
{
	if (_owner == nullptr) return;
	Vec2 pos = GetPosition() + _owner->GetPosition();
	if (_parent != nullptr)
		pos += _parent->GetPosition();

	Vec2 size = GetSize();

	D2D1_RECT_F rect = { pos.x - size.x / 2, pos.y - size.y / 2, pos.x + size.x / 2, pos.y + size.y / 2 };  // 출력할 영역

	if (_brush == nullptr) return;

	renderTarget->DrawTextW(
		_text.c_str(),
		_text.size(),
		_textFormat.Get(),
		rect,
		_brush.Get()
	);
}

void Text::LoadFont(std::wstring fontName, float fontSize)
{
    std::wstring fullPath = GET_MANAGER(ResourceManager)->GetResPath();
    fullPath += L"Font\\" + fontName + L".ttf";

    if (!GET_MANAGER(ResourceManager)->LoadFont(fontName, fullPath))
    {
        std::wcout << L"LoadFont failed for path: " << fullPath << std::endl;
        return;
    }

    ComPtr<IDWriteFontCollection> fontCollection = GET_MANAGER(ResourceManager)->GetFontCollection();
    if (!fontCollection)
    {
        std::wcout << L"No custom font collection available" << std::endl;
        return;
    }

    std::wstring familyToUse;
    UINT32 familyCount = fontCollection->GetFontFamilyCount();
    for (UINT32 i = 0; i < familyCount; ++i)
    {
        ComPtr<IDWriteFontFamily> family;
        if (FAILED(fontCollection->GetFontFamily(i, &family)) || !family) continue;

        ComPtr<IDWriteLocalizedStrings> names;
        if (FAILED(family->GetFamilyNames(&names)) || !names) continue;

        UINT32 nameCount = 0;
        nameCount = names->GetCount();
        for (UINT32 n = 0; n < nameCount; ++n)
        {
            UINT32 length = 0;
            names->GetStringLength(n, &length);
            std::wstring buf(length + 1, L'\0');
            names->GetString(n, buf.data(), length + 1);
            buf.resize(length);

            if (familyToUse.empty())
                familyToUse = buf; 

            if (buf == fontName)
            {
                familyToUse = buf;
                break;
            }
        }
        if (!familyToUse.empty() && familyToUse == fontName)
            break;
    }

    if (familyToUse.empty())
    {
        std::wcout << L"Failed to find any family name in custom collection" << std::endl;
        return;
    }

    HRESULT hr = GET_MANAGER(ResourceManager)->GetWriteFactory()->CreateTextFormat(
        familyToUse.c_str(),
        fontCollection.Get(),
        _weight, _style, _stretch,
        fontSize, L"ko-KR", &_textFormat
    );

    if (SUCCEEDED(hr))
    {
        wchar_t nameBuf[256] = {};
        _textFormat->GetFontFamilyName(nameBuf, 256);
        std::wcout << L"Requested: " << fontName << L" / Applied: " << nameBuf << std::endl;
    }
    else
    {
        std::wcout << L"CreateTextFormat failed for family: " << familyToUse << L" hr=" << std::hex << hr << std::endl;
    }
}

void Text::SetColor(D2D1::ColorF color)
{
	_color = color;

	ZeroMemory(_brush.GetAddressOf(), sizeof(_brush));

	GET_SINGLE(Core)->GetRenderTarget()->CreateSolidColorBrush(_color, _brush.GetAddressOf());
}