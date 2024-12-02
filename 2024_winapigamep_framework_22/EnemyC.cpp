#include "pch.h"
#include "EnemyC.h"
#include "ResourceManager.h"
#include "TimeManager.h"
#include "Texture.h"
#include "Animator.h"
#include "AttackCompo.h"
#include "HealthCompo.h"

EnemyC::EnemyC()
{
	SetSize({ 100,100 });
	_target = FindObject(L"Player", LAYER::PLAYER);
	_texture = LOADTEXTURE(L"Enemy02", L"Texture\\Enemy02.bmp");
	Vec2 texSize = Vec2((int)_texture->GetWidth() / 7, (int)_texture->GetHeight());

	AddComponent<Animator>();
	AddComponent<AttackCompo>();
	AddComponent<HealthCompo>();

	GetComponent<Animator>()
		->CreateAnimation(L"Enemy02Idle", _texture, { 0,0 }, texSize, { (int)texSize.x, 0 }, 7, 0.2f, false);
	GetComponent<Animator>()->PlayAnimation(L"Enemy02Idle", true, 100);
	GetComponent<HealthCompo>()->SetOffsetY(60);

	_prevShootTime = TIME;
}

EnemyC::~EnemyC()
{
}

void EnemyC::Update()
{
	if (_prevShootTime + _shootDelay < TIME)
	{
		_prevShootTime = TIME;

		Vec2 dir = _target->GetPos();
		dir -= GetPos();

		float rotation = atan2(dir.y, dir.x) * Rad2Deg;
		Vec2 dir1 = { cos((rotation - 30) * Deg2Rad) , sin((rotation - 30) * Deg2Rad) };
		Vec2 dir2 = { cos((rotation + 30) * Deg2Rad), sin((rotation + 30) * Deg2Rad) };

		GetComponent<AttackCompo>()->TryFireBullet(dir);
		GetComponent<AttackCompo>()->TryFireBullet(dir1);
		GetComponent<AttackCompo>()->TryFireBullet(dir2);
	}
}

void EnemyC::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}