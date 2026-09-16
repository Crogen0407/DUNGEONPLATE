#include "pch.h"
#include "Background.h"
#include "Collider.h"
#include "EventManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "SpriteRenderer.h"
#include "Stage.h"
#include "StageLoader.h"
#include "Enemy.h"
#include "HealthCompo.h"
#include "Core.h"
#include <fstream>
#include <sstream>
#include <locale>
#include <codecvt>

Background::Background() : 
    _currentEnemyCount(0), 
    _currentSpawnedEnemyIndex(0)
{
	AddComponent<Collider>();
	_spriteRenderer = AddComponent<SpriteRenderer>();
	Collider* collider = GetComponent<Collider>();
	collider->SetSize(StageLoader::mapSize);
	collider->SetOffSetPosition({ 0, 0 });
	_spriteRenderer->SetTexture(L"Background", L"Texture\\Background.png");

    LoadFont(L"PFstardust", 40.f);

	_textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
	_textFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

	GET_SINGLE(Core)->GetRenderTarget()->CreateSolidColorBrush(D2D1::ColorF(0x0f380f), _brush.GetAddressOf());

	_enemySpawner = new EnemySpawner;
}

Background::~Background()
{
	delete(_enemySpawner);
}

void Background::Render(ComPtr<ID2D1RenderTarget> renderTarget)
{
	Object::Render(renderTarget);

	if (_maxEnemyCount- _currentEnemyCount <= 0) return;
	Vec2 pos = GetPosition();
	Vec2 size = GetSize();
	D2D1_RECT_F rect = { pos.x - size.x / 2, pos.y - size.y / 2, pos.x + size.x / 2, pos.y + size.y / 2 };  // 출력할 영역
	float offset = 5;
	rect.top += offset;
	rect.bottom += offset;
	wstring str = std::to_wstring(_maxEnemyCount - _currentEnemyCount).c_str();

	renderTarget->DrawTextW(
		str.c_str(),
		str.size(),
		_textFormat.Get(),
		rect,
		_brush.Get()
	);

}

void Background::SpawnEnemy(EnemyType enemyType, const Vec2& pos)
{
	if (_currentSpawnedEnemyIndex >= _maxEnemyCount) return;

    ++_currentSpawnedEnemyIndex;
	Enemy* enemy = _enemySpawner->SpawnEnemy(pos, enemyType);
	enemy->GetComponent<HealthCompo>()->DieEvent += [this](int _)
		{
            ++_currentEnemyCount;
            cout << _currentEnemyCount << endl;
			if (_maxEnemyCount - _currentEnemyCount > 0) return;
			isClear = true;
			owner->stageLoader->TryNextStage();
		};
}

void Background::SpawnEnemyByRandomPos(EnemyType enemyType)
{
	srand(time(NULL));
	int offset = 50;

	Vec2 size = Vec2((GetSize().x - offset), (GetSize().y - offset));

	float ranX = (rand() % (int)size.x) - (int)size.x / 2 + GetPosition().x;
	float ranY = (rand() % (int)size.y) - (int)size.y / 2 + GetPosition().y;
	Vec2 pos = { ranX, ranY };

	SpawnEnemy(enemyType, pos);
}

void Background::LoadFont(std::wstring fontName, float fontSize)
{
    std::wstring fullPath = GET_MANAGER(ResourceManager)->GetResPath();
    fullPath += L"Font\\" + fontName + L".ttf";

    if (!GET_MANAGER(ResourceManager)->LoadFont(fontName, fullPath))
    {
        std::wcout << L"Background::LoadFont failed for path: " << fullPath << std::endl;
        return;
    }

    ComPtr<IDWriteFontCollection> fontCollection = GET_MANAGER(ResourceManager)->GetFontCollection();
    if (!fontCollection)
    {
        std::wcout << L"Background::LoadFont - no custom font collection available" << std::endl;
        return;
    }

    UINT32 familyCount = fontCollection->GetFontFamilyCount();

    std::wstring familyToUse;
    for (UINT32 i = 0; i < familyCount; ++i)
    {
        ComPtr<IDWriteFontFamily> family;
        if (FAILED(fontCollection->GetFontFamily(i, &family)) || !family) continue;

        ComPtr<IDWriteLocalizedStrings> names;
        if (FAILED(family->GetFamilyNames(&names)) || !names) continue;

        UINT32 nameCount = names->GetCount();

        for (UINT32 n = 0; n < nameCount; ++n)
        {
            UINT32 length = 0;
            names->GetStringLength(n, &length);
            std::wstring buf(length + 1, L'\0');
            names->GetString(n, buf.data(), length + 1);
            buf.resize(length);

            std::wostringstream hexss;
            for (wchar_t c : buf)
                hexss << L" " << std::hex << std::uppercase << (uint16_t)c;


            if (familyToUse.empty() && buf == fontName)
                familyToUse = buf;
        }
    }

    if (familyToUse.empty())
    {
        auto normalize = [](const std::wstring& s) {
            std::wstring out;
            for (wchar_t c : s) if (iswalnum(c)) out.push_back(towlower(c));
            return out;
        };
        std::wstring reqNorm = normalize(fontName);

        for (UINT32 i = 0; i < familyCount && familyToUse.empty(); ++i)
        {
            ComPtr<IDWriteFontFamily> family;
            if (FAILED(fontCollection->GetFontFamily(i, &family)) || !family) continue;
            ComPtr<IDWriteLocalizedStrings> names;
            if (FAILED(family->GetFamilyNames(&names)) || !names) continue;

            UINT32 nameCount = names->GetCount();
            for (UINT32 n = 0; n < nameCount; ++n)
            {
                UINT32 length = 0;
                names->GetStringLength(n, &length);
                std::wstring buf(length + 1, L'\0');
                names->GetString(n, buf.data(), length + 1);
                buf.resize(length);

                std::wstring bufNorm = normalize(buf);
                if (bufNorm.find(reqNorm) != std::wstring::npos) { familyToUse = buf; break; }
                if (familyToUse.empty()) familyToUse = buf;
            }
        }
    }

    if (familyToUse.empty())
    {
        std::wcout << L"Background::LoadFont - failed to determine family name\n";
        return;
    }

    HRESULT hr = GET_MANAGER(ResourceManager)->GetWriteFactory()->CreateTextFormat(
        familyToUse.c_str(),
        fontCollection.Get(),
        DWRITE_FONT_WEIGHT_NORMAL,
        DWRITE_FONT_STYLE_NORMAL,
        DWRITE_FONT_STRETCH_NORMAL,
        fontSize, L"ko-KR", &_textFormat
    );

    if (FAILED(hr) || !_textFormat)
    {
        std::wcout << L"Background::LoadFont - CreateTextFormat failed hr=0x" << std::hex << hr << std::endl;
        return;
    }

    // 브러시 생성 (렌더타겟이 유효한 시점에서 호출되어야 함)
    if (GET_SINGLE(Core)->GetRenderTarget())
    {
        GET_SINGLE(Core)->GetRenderTarget()->CreateSolidColorBrush(D2D1::ColorF(0x0f380f), _brush.GetAddressOf());
    }

    wchar_t nameBuf[256] = {};
    _textFormat->GetFontFamilyName(nameBuf, 256);
    std::wcout << L"Background::LoadFont Requested: " << fontName << L" / Applied: " << nameBuf << std::endl;
}
