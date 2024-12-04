#include "pch.h"
#include "Background.h"
#include "Collider.h"
#include "EventManager.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "SpriteRenderer.h"

Background::Background()
{
	AddComponent<SpriteRenderer>();
	_spriteRenderer = GetComponent<SpriteRenderer>();
	_spriteRenderer->isRotatable = false;
	_spriteRenderer->SetTexture(L"Background", L"Texture\\Background.bmp");

	_font = CreateFont(40, 30,
		0, 0, 0, 0, 0, 0, HANGEUL_CHARSET,
		0, 0, 0, VARIABLE_PITCH | FF_ROMAN, L"PF스타더스트 Bold");
}

Background::~Background()
{

}

void Background::Update()
{
}

void Background::Render(HDC _hdc)
{
    ComponentRender(_hdc);

	if (_currentEnemyCount <= 0) return;
	Vec2 pos = GetPos();
	Vec2 size = GetSize();
	::SetTextColor(_hdc, RGB(155, 188, 15));
	HFONT oldFont = static_cast<HFONT>(SelectObject(_hdc, _font));

	::SetBkMode(_hdc, 1);
	RECT rect = { pos.x - size.x / 2, pos.y - size.y / 2, pos.x + size.x / 2, pos.y + size.y / 2 };  // 출력할 영역

	::DrawText(_hdc, std::to_wstring(_currentEnemyCount).c_str(), -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	SetTextColor(_hdc, RGB(0, 0, 0));
	SelectObject(_hdc, oldFont);
}

void Background::SpawnEnemyByRandomPos(EnemyType enemyType)
{
	srand(time(NULL));

	int ranX = (rand() % (int)GetSize().x) + GetPos().x;
	int ranY = (rand() % (int)GetSize().y) + GetPos().y;

	SpawnEnemy({ ranX, ranY }, enemyType);
}
