#include "pch.h"
#include "GuidedMissile.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "EventManager.h"
#include "TimeManager.h"
#include "Collider.h"

GuidedMissile::GuidedMissile()
{
	SetSize({ 20,20 });
	_texture = LOADTEXTURE(L"EnemyMissile", L"Texture\\EnemyMissile.bmp");
	AddComponent<Collider>();
	AddComponent<SpriteRenderer>();

	GetComponent<Collider>()->SetSize({ 20.f,20.f });
	GetComponent<SpriteRenderer>()->SetTexture(_texture);

	target = FindObject(L"Player", LAYER::PLAYER);
	spawnedTime = TIME;

	_dir = target->GetPos();
	_dir -= GetPos();
	_dir.Normalize();

	_rotation = atan2f(_dir.y, _dir.x) * Rad2Deg;
}

GuidedMissile::~GuidedMissile()
{
}

void GuidedMissile::Update()
{
	Vec2 vPos = GetPos();
	Vec2 targetDir = (vPos * -1) + target->GetPos();
	targetDir.Normalize();

	float cross = targetDir.Cross(_dir);

	if (cross > 0)
		_rotation -= 2.7f * fDT;
	else if (cross < 0)
		_rotation += 2.7f * fDT;


	_dir = { cosf(_rotation) , sinf(_rotation) };
	_dir.Normalize();

	if (spawnedTime + lifetime < TIME)
		GET_SINGLE(EventManager)->DeleteObject(this);

	vPos.x += _dir.x * speed * fDT;
	vPos.y += _dir.y * speed * fDT;
	SetPos(vPos);

	GetComponent<SpriteRenderer>()->LookAt(_dir);

	Vec2 vSize = GetSize();
	if (vPos.y < -vSize.y)
		GET_SINGLE(EventManager)->DeleteObject(this);
}

void GuidedMissile::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}
