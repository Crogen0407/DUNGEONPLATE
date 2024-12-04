#include "pch.h"
#include "GuidedMissile.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "EventManager.h"
#include "TimeManager.h"
#include "Collider.h"
#include "ExplosionEffect.h"
#include "SceneManager.h"
#include "Scene.h"

GuidedMissile::GuidedMissile()
{
	damage = 3;
	_hitEnemy = false;
	SetSize({ 20,20 });
	_texture = LOADTEXTURE(L"EnemyMissile", L"Texture\\EnemyMissile.bmp");
	AddComponent<Collider>();
	AddComponent<SpriteRenderer>();

	GetComponent<Collider>()->SetSize({ 20.f,20.f });
	GetComponent<SpriteRenderer>()->SetTexture(_texture);

	target = FindObject(L"Player", LAYER::PLAYER);
	_spawnedTime = TIME;
	speed = 400;

	/*_dir = target->GetPos();
	_dir -= GetPos();
	_dir.Normalize();
	_rotation = atan2f(_dir.y, _dir.x) * Rad2Deg;*/
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
		_rotation -= 3.f * fDT;
	else if (cross < 0)
		_rotation += 3.f * fDT;

	_dir = { cos(_rotation), sin(_rotation) };

	vPos.x += _dir.x * speed * fDT;
	vPos.y += _dir.y * speed * fDT;
	SetPos(vPos);

	if (_spawnedTime + _lifetime < TIME)
	{
		ExplosionEffect* explosion = new ExplosionEffect(L"ExplosionEffect02");
		explosion->SetPos(GetPos());
		GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(explosion, LAYER::SCREENEFFECT);

		GET_SINGLE(EventManager)->DeleteObject(this);
	}
}

void GuidedMissile::Render(HDC _hdc)
{
	ComponentRender(_hdc);
	GetComponent<SpriteRenderer>()->LookAt(_dir);
}

void GuidedMissile::SetDir(Vec2 dir)
{
	_dir = dir;
	_dir.Normalize();
	_rotation = atan2f(_dir.y, _dir.x) * Rad2Deg;
}
