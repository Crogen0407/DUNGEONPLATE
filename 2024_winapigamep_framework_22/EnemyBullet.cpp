#include "pch.h"
#include "EnemyBullet.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "TimeManager.h"
#include "Collider.h"
#include "Texture.h"
#include "SpriteRenderer.h"

EnemyBullet::EnemyBullet()
{
	_texture = LOADTEXTURE(L"EnemyBullet", L"Texture\\EnemyBullet.bmp");
	AddComponent<SpriteRenderer>();
	AddComponent<Collider>();

	GetComponent<Collider>()->SetSize({ 20.f,20.f });
	GetComponent<SpriteRenderer>()->SetTexture(_texture);
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Update()
{
	Vec2 vPos = GetPos();

	vPos.x += _dir.x * speed * fDT;
	vPos.y += _dir.y * speed * fDT;
	SetPos(vPos);
	Vec2 vSize = GetSize();
	if (vPos.y < -vSize.y)
	{
		GET_SINGLE(EventManager)->DeleteObject(this);
	}
}

void EnemyBullet::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();

	int width = _texture->GetWidth();
	int height = _texture->GetHeight();
	::TransparentBlt(_hdc
		, (int)(vPos.x - width / 2)
		, (int)(vPos.y - height / 2)
		, width, height,
		_texture->GetTexDC()
		, 0, 0, width, height, RGB(255, 0, 255));
	ComponentRender(_hdc);
}
