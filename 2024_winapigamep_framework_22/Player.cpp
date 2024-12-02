#include "pch.h"
#include "Player.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Projectile.h"
#include "Scene.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "SpriteRenderer.h"
#include "PlayerHealthCompo.h"
#include "Action.h"
#include "SceneManager.h"
#include "AttackDirArrow.h"
#include "GameManager.h"
#include "SkillManager.h"
#include "PoolManager.h"
#include "SlashEffect.h"

Player::Player()
{
	this->AddComponent<Collider>();
	this->AddComponent<SpriteRenderer>();
	this->AddComponent<PlayerHealthCompo>();

	_spriteRenderer = GetComponent<SpriteRenderer>();
	healthCompo = GetComponent<PlayerHealthCompo>();
	collider = GetComponent<Collider>();

	_spriteRenderer->SetTexture(L"Player", L"Texture\\Player.bmp");
	_spriteRenderer->isRotatable = false;
	healthCompo->SetHpBarActive(0);
	collider->SetSize({ 25, 25 });

	//나중에 밸패하기
	SetSize({ 75, 75 });
	speed = 400;
	parryCoolTime = 0.87f;

	AttackDirArrow* arrow = new AttackDirArrow;
	arrow->SetParent(this);
	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(arrow, LAYER::UI);
	GET_SINGLE(SkillManager)->player = this;
	GET_SINGLE(GameManager)->player = this;
}
Player::~Player()
{
}

void Player::Update()
{
	Vec2 dir;
	if (GET_KEY(KEY_TYPE::W))
		dir += Vec2(0, -1);
	if (GET_KEY(KEY_TYPE::S))
		dir += Vec2(0, 1);
	if (GET_KEY(KEY_TYPE::A))
		dir += Vec2(-1, 0);
	if (GET_KEY(KEY_TYPE::D))
		dir += Vec2(1, 0);
	if (GET_KEYDOWN(KEY_TYPE::LBUTTON))
	{
		if (TIMESCALE <= 0.01f) return;
		Parry();
	}
	dir.Normalize();

	attackDir = ((Vec2)GET_MOUSEPOS - GetPos());
	attackDir.Normalize();

	Move(dir * speed * fDT);
	Parrying();

	Vec2 vPos = GetPos();

	Vec2 lookDir = (Vec2)GET_MOUSEPOS - GetPos();

	if (GET_KEYDOWN(KEY_TYPE::CTRL))
	{
		healthCompo->ApplyDamage(55);
	}

	_spriteRenderer->LookAt(lookDir);
	SetPos(vPos);
}

void Player::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void Player::Parry()
{
	if (isParrying == true) return;
	if (curParryTime < parryCoolTime)
	{
		return;
	}
	curParryTime = 0;

	{
		Vec2 effectPos = GetPos();
		effectPos += attackDir * 50.f;
		SlashEffect* slashEffect = static_cast<SlashEffect*>(POP(L"SlashEffect", effectPos));
		slashEffect->LookAt(attackDir);
	}
	
	isParrying = true;
}

void Player::Parrying()
{
	if (curParryTime < parryCoolTime)
	{
		curParryTime += fDT;
		ParryCoolTimeEvent.Invoke(curParryTime / parryCoolTime);
	}

	if (curParryTime > parryingTime || isParrying == false)
	{
		isParrying = false;
		return;
	}

	Vec2 vPos = GetPos();
	bool parried = false;
	vector<Object*> projectiles = FindObjects(LAYER::PROJECTILE);

	for (Object* projObj : projectiles)
	{
		Vec2 dist = vPos - projObj->GetPos();
		if (dist.Length() > parryDist) continue;

		Projectile* proj = (Projectile*)projObj; 
		proj->Parry();
		parried = true;
	}

	if (projectiles.size() > 0)
		AttackEvent.Invoke(NULL);

	if (parried) isParrying = false;
}

void Player::EnterCollision(Collider* _other)
{
	healthCompo->ApplyDamage(10);
}

void Player::StayCollision(Collider* _other)
{
}

void Player::ExitCollision(Collider* _other)
{
}