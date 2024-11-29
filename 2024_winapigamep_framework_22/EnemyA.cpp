#include "pch.h"
#include "EnemyA.h"
#include "Enemy.h"
#include "Scene.h"
#include "Player.h"
#include "Object.h"
#include "Texture.h"
#include "Projectile.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "AttackCompo.h"
#include "Movement.h"
#include "GuidedMissile.h"
#include "SpriteRenderer.h"
#include "Animator.h"
#include "Animation.h"

EnemyA::EnemyA()
{
	m_moveDesire = Vec2(0, 0);
	target = FindObject(L"Player", LAYER::PLAYER);
	SetSize({ 100, 100 });

	Texture* texture = LOADTEXTURE(L"Enemy01", L"Texture\\Enemy01.bmp");
	Vec2 texSize = Vec2((int)texture->GetWidth() / 3, (int)texture->GetHeight());

	AddComponent<Animator>();
	AddComponent<AttackCompo>();
	AddComponent<Movement>();

	GetComponent<Animator>()
		->CreateAnimation(L"Enemy01Idle", texture, {0,0}, texSize, { (int)texSize.x, 0}, 3, 0.2f);
	GetComponent<Animator>()->PlayAnimation(L"Enemy01Idle", true, 5);
}

EnemyA::~EnemyA()
{
}

void EnemyA::Update()
{
	if (prevShootTime + shootDelay < TIME)
	{
		prevShootTime = TIME;

		Vec2 attackDir = target->GetPos();
		attackDir -= GetPos();
		GetComponent<AttackCompo>()->TryFireBullet(attackDir);
	}

	if (prevDash + 2 < TIME)
	{
		prevDash = TIME;

		Vec2 dashDir = { rand() % 2 == 0 ? 1 : -1, 0 };
		if (GetPos().x < 100) dashDir = { 1,0 };
		else if (GetPos().x > SCREEN_WIDTH - 100) dashDir = { -1,0 };

		GetComponent<Movement>()->Dash(dashDir, 1000.f, 0.1f);
	}
}

void EnemyA::Render(HDC _hdc)
{
	ComponentRender(_hdc);
	//cout << (int)GetComponent<Animator>()->FindAnimation(L"Enemy01Idle")->GetCurFrame();
	/*HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldbrush = (HBRUSH)SelectObject(_hdc, brush);

	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	RECT_RENDER(_hdc, vPos.x, vPos.y, vSize.x, vSize.y);

	SelectObject(_hdc, oldbrush);
	DeleteObject(brush);*/
}

//void EnemyA::Fire()
//{
//	prevShootTime = TIME;
//
//	Vec2 dir = player->GetPos();
//	dir -= GetPos();
//
//	Projectile* projectile = new Projectile();
//	projectile->SetPos(GetPos());
//	projectile->SetSize({ 10, 10 });
//
//	GET_SINGLE(SceneManager)->GetCurrentScene()
//		->AddObject(projectile, LAYER::PROJECTILE);
//
//	projectile->SetDir(dir);
//}
