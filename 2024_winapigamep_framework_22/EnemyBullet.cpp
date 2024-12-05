#include "pch.h"
#include "EnemyBullet.h"
#include "ResourceManager.h"
#include "PoolManager.h"
#include "TimeManager.h"
#include "Collider.h"
#include "Texture.h"
#include "SpriteRenderer.h"

EnemyBullet::EnemyBullet()
{
	_damage = 10;
	_poolName = L"EnemyBullet";
	_texture = LOADTEXTURE(L"EnemyBullet", L"Texture\\EnemyBullet.bmp");
	AddComponent<SpriteRenderer>();
	AddComponent<Collider>();
	SetSize({ 20,20 });

	GetComponent<Collider>()->SetSize({ 20.f,20.f });
	GetComponent<SpriteRenderer>()->SetTexture(_texture);
}

EnemyBullet::~EnemyBullet()
{
}

static int cnt = 0;
void EnemyBullet::Update()
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	_dir.Normalize();

	vPos.x += _dir.x * _speed * fDT;
	vPos.y += _dir.y * _speed * fDT;

	SetPos(vPos);
	if (vPos.y < -vSize.y / 2 || vPos.x < -vSize.x / 2
		|| vPos.y > SCREEN_HEIGHT + vSize.y || vPos.x > SCREEN_WIDTH)
	{
		PUSH(_poolName, this);
	}
}

void EnemyBullet::Render(HDC _hdc)
{
	/*Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();

	int width = _texture->GetWidth();
	int height = _texture->GetHeight();
	::TransparentBlt(_hdc
		, (int)(vPos.x - width / 2)
		, (int)(vPos.y - height / 2)
		, width, height,
		_texture->GetTexDC()
		, 0, 0, width, height, RGB(255, 0, 255));*/
	ComponentRender(_hdc);
}

void EnemyBullet::OnPop()
{
	_hitEnemy = false;
	_speed = 0;
}

void EnemyBullet::OnPush()
{
}
