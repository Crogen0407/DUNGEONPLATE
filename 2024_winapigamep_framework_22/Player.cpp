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
#include "AttackRange.h"
#include "PlayerManager.h"
#include "SkillManager.h"
#include "PoolManager.h"
#include "SlashEffect.h"
#include "PlayerCast.h"
#include "DashSkill.h"
#include "MapBounds.h"

Player::Player()
{
	_spriteRenderer = this->AddComponent<SpriteRenderer>();;
	healthCompo = this->AddComponent<PlayerHealthCompo>();
	collider = this->AddComponent<Collider>();

	_playerCasts.push_back(new PlayerCast(30.f));
	_playerCasts.push_back(new PlayerCast);
	_playerCasts.push_back(new PlayerCast(-30.f));

	_spriteRenderer->SetTexture(L"Player", L"Texture\\Player.png");
	collider->SetSize({ 25, 25 });

	//나중에 밸패하기
	SetSize({ 45, 45 });
	speed = 400;
	parryCoolTime = 0.87f;

	AttackDirArrow* arrow = new AttackDirArrow;
	arrow->SetParent(this);

	attackRange = new AttackRange;
	attackRange->SetParent(this);

	ADDOBJECT(attackRange, LAYER::DEFAULT);
	ADDOBJECT(arrow, LAYER::DEFAULT);

	for (auto playerCast : _playerCasts)
	{
		ADDOBJECT(playerCast, LAYER::PLAYERCAST);
	}

	GET_MANAGER(SkillManager)->player = this;
	GET_SINGLE(PlayerManager)->player = this;
	LOADSOUND(L"Parry", L"Sound\\Parry.wav", SOUND_CHANNEL::EFFECT0);
	LOADSOUND(L"Sword", L"Sound\\sword.wav", SOUND_CHANNEL::EFFECT1);
}

Player::~Player()
{
}

void Player::Update()
{
	Vec2 dir = OnMoveInput();
	if (dir.LengthSquared() > 0.1f)
		_lastMoveDirection = dir;

	if (GET_KEYDOWN(KEY_TYPE::LBUTTON))
	{
		if (TIMESCALE < 0.01f) return;
		Parry();
	}

	bool isTrigger = false;

	for (auto playerCast : _playerCasts)
	{
		playerCast->SetPosition(GetPosition());
		playerCast->SetMoveDir(_lastMoveDirection);
		dir.Normalize();
	}
	for (auto playerCast : _playerCasts)
	{
		if (playerCast->IsCast())
		{
			isTrigger = true;
			break;
		}
	}

	if (isTrigger)
	{
		Move(dir * speed * fDT);
	}
	else
	{
		DashSkill* dashSkill = dynamic_cast<DashSkill*>(GET_MANAGER(SkillManager)->GetSkill(ESkillType::DashSkill));
		dashSkill->StopDash();
		SetPosition(lastPos);
	}

	// 이동 결과를 항상 유효 영역으로 보정
	Vec2 pos = GetPosition();
	if (!GET_SINGLE(MapBounds)->IsInside(pos))
		SetPosition(GET_SINGLE(MapBounds)->ClosestPoint(pos));
	
	lastPos = pos;

	attackDir = (GET_MOUSEPOS - GetPosition());
	attackDir.Normalize();
	attackRange->SetDir(attackDir);
	Parrying();

	if (GET_KEYDOWN(KEY_TYPE::CTRL))
		healthCompo->ApplyDamage(55);

	if (TIMESCALE > 0.1f)
		_spriteRenderer->LookAt(attackDir);
}

void Player::Parry()
{
	if (isParrying == true) return;
	if (curParryTime < parryCoolTime)
	{
		return;
	}
	curParryTime = 0;
	AttackEvent.Invoke(NULL);

	{
		Vec2 effectPos = GetPosition();
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

	Vec2 vPos = GetPosition();
	bool parried = false;
	vector<Object*> projectiles = FindObjects(LAYER::PROJECTILE);

	for (Object* projObj : projectiles)
	{
		Projectile* proj = dynamic_cast<Projectile*>(projObj);

		Vec2 dist = projObj->GetPosition();
		dist -= vPos;
		if (dist.Length() > parryDist) continue;

		attackDir.Normalize();
		dist.Normalize();

		float rotation = acos(attackDir.Dot(dist)) * Rad2Deg;
		if (abs(rotation) < 45)
		{
			if (proj == nullptr) continue;
			proj->Parry();
			parried = true;
		}
	}

	PLAY(L"Sword");

	if (parried)
		isParrying = false;
}

Vec2 Player::OnMoveInput()
{
	Vec2 dir = Vec2(0, 0);
	if (GET_KEY(KEY_TYPE::W))
		dir += Vec2(0, -1);
	if (GET_KEY(KEY_TYPE::S))
		dir += Vec2(0, 1);
	if (GET_KEY(KEY_TYPE::A))
		dir += Vec2(-1, 0);
	if (GET_KEY(KEY_TYPE::D))
		dir += Vec2(1, 0);
	dir.Normalize();
	return dir;
}

void Player::EnterCollision(Collider* _other)
{
}

void Player::StayCollision(Collider* _other)
{
}

void Player::ExitCollision(Collider* _other)
{
}
