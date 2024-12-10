#include "pch.h"
#include "EnemyB.h"
#include "Enemy.h"
#include "Scene.h"
#include "Player.h"
#include "Object.h"
#include "Projectile.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "AttackCompo.h"
#include "HealthCompo.h"
#include "Movement.h"
#include "Animator.h"
#include "ResourceManager.h"
#include "Texture.h"
#include "EventManager.h"

EnemyB::EnemyB()
{
	_giveExp = 4;
	SetSize({ 50,50 });
	_target = FindObject(L"Player", LAYER::PLAYER);
	texture = LOADTEXTURE(L"Enemy02", L"Texture\\Enemy02.bmp");
	Vec2 texSize = Vec2((int)texture->GetWidth() / 7, (int)texture->GetHeight());

	prevShootTime = TIME;
	AddComponent<Animator>();
	AddComponent<AttackCompo>();
	//AddComponent<HealthCompo>();

	GetComponent<Animator>()
		->CreateAnimation(L"Enemy02Idle", texture, { 0,0 }, texSize, { (int)texSize.x, 0 }, 7, 0.2f, false);
	GetComponent<Animator>()->PlayAnimation(L"Enemy02Idle", true, 100);

	GetComponent<HealthCompo>()->SetOffsetY(40);
	GetComponent<HealthCompo>()->SetHp(30,30);
}

EnemyB::~EnemyB()
{
}

float _rotation = 0;

void EnemyB::Update()
{
	float delay = shootDelay;

	if (prevShootTime + delay < TIME)
	{
		prevShootTime = TIME;

		for (int i = 0; i < 4; i++)
		{
			Vec2 attackDir = { sin(_rotation * Deg2Rad), cos(_rotation * Deg2Rad) };
			GetComponent<AttackCompo>()->TryFireBullet(attackDir, 500);

			_rotation += 90;
		}

		_rotation += 45;
	}
}

void EnemyB::Render(HDC _hdc)
{
	ComponentRender(_hdc);
	/*HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH oldbrush = (HBRUSH)SelectObject(_hdc, brush);

	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	RECT_RENDER(_hdc, vPos.x, vPos.y, vSize.x, vSize.y);

	SelectObject(_hdc, oldbrush);
	DeleteObject(brush);*/
}
