#include "pch.h"
#include "GuidedMissile.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "TimeManager.h"
#include "Collider.h"
#include "ExplosionEffect.h"
#include "SceneManager.h"
#include "Scene.h"
#include "AttackCompo.h"
#include "HealthCompo.h"
#include "PoolManager.h"

GuidedMissile::GuidedMissile()
{
	_poolName = L"GuidedMissile";
	_damage = 7;
	SetSize({ 20,20 });
	_texture = LOADTEXTURE(L"EnemyMissile", L"Texture\\EnemyMissile.bmp");
	AddComponent<Collider>();
	AddComponent<SpriteRenderer>();
	AddComponent<AttackCompo>();

	GetComponent<Collider>()->SetSize({ 20.f,20.f });
	GetComponent<SpriteRenderer>()->SetTexture(_texture);

	target = FindObject(L"Player", LAYER::PLAYER);
	_speed = 400;

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

	_curTime += fDT;

	if (_isParry)
	{
		//_dir = targetDir;
	}
	else
	{
		float cross = targetDir.Cross(_dir);

		if (cross > 0)
			_rotation -= 3.f * fDT;
		else if (cross < 0)
			_rotation += 3.f * fDT;

		_dir = { cos(_rotation), sin(_rotation) };
	}

	if (_prevAttack + _attackDelay < TIME)
	{
		_prevAttack = TIME;

		Vec2 dir1 = { cos(_rotation + 150 * Deg2Rad), sin(_rotation + 150 * Deg2Rad) };
		Vec2 dir2 = { cos(_rotation - 150 * Deg2Rad), sin(_rotation - 150 * Deg2Rad) };

		GetComponent<AttackCompo>()->TryFireBullet(dir1, 200);
		GetComponent<AttackCompo>()->TryFireBullet(dir2, 200);
	}

	vPos.x += _dir.x * _speed * fDT;
	vPos.y += _dir.y * _speed * fDT;
	SetPos(vPos);

	if (_lifetime < _curTime)
	{
		ExplosionEffect* explosion = new ExplosionEffect(L"ExplosionEffect02");
		explosion->SetPos(GetPos());
		GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(explosion, LAYER::SCREENEFFECT);

		PUSH(_poolName, this);
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

void GuidedMissile::Parry(Vec2 dir)
{
	Vec2 parriedDir = (_dir * -1) + GetPos();
	parriedDir.Normalize();

	SetDir(parriedDir);
	_hitEnemy = true;
	_isParry = true;
}

void GuidedMissile::EnterCollision(Collider* _other)
{
	LAYER layer =
		GET_SINGLE(SceneManager)->GetCurrentScene()->GetLayer(_other->GetOwner());

	if (layer == LAYER::PLAYER /*|| (layer == LAYER::ENEMY && _hitEnemy)*/)
	{
		HealthCompo* health = _other->GetOwner()->GetComponent<HealthCompo>();

		if (health != nullptr)
			health->ApplyDamage(_damage); 
		
		ExplosionEffect* explosion = new ExplosionEffect(L"ExplosionEffect02");
		explosion->SetPos(GetPos());
		GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(explosion, LAYER::SCREENEFFECT);

		Object* pOtherObj = _other->GetOwner();
		PUSH(_poolName, this);
	}
}

void GuidedMissile::OnPop()
{
	_hitEnemy = false;
	_isParry = false;
}

void GuidedMissile::OnPush()
{
	_curTime = 0.f;
}
