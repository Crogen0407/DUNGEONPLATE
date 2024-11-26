#include "pch.h"
#include "Player.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "Projectile.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "SpriteRenderer.h"

Player::Player()
	: m_pTex(nullptr)
{
	//m_pTex = new Texture;
	//wstring path = GET_SINGLE(ResourceManager)->GetResPath();
	//path += L"Texture\\planem.bmp";
	//m_pTex->Load(path);
	//m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Player", L"Texture\\planem.bmp");
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Jiwoo", L"Texture\\jiwoo.bmp");
	this->AddComponent<Collider>();
	this->AddComponent<SpriteRenderer>();
	_spriteRenderer = GetComponent<SpriteRenderer>();
	_spriteRenderer->SetTexture(L"planem", L"Texture\\planem.bmp");
	//AddComponent<Animator>();
	//GetComponent<Animator>()->CreateAnimation(L"JiwooFront", m_pTex, Vec2(0.f, 150.f),
	//	Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.1f);
	//GetComponent<Animator>()->PlayAnimation(L"JiwooFront", true);



}
Player::~Player()
{
}
Vec2 dir;

void Player::Update()
{
	if (GET_KEY(KEY_TYPE::W))
		dir = Vec2(0, -1);
	if (GET_KEY(KEY_TYPE::S))
		dir = Vec2(0, 1);
	if (GET_KEY(KEY_TYPE::A))
		dir = Vec2(-1, 0);
	if (GET_KEY(KEY_TYPE::D))
		dir = Vec2(1, 0);
	if (GET_KEY(KEY_TYPE::SPACE))
		Parry();

	Move(dir * speed * fDT);
	Parrying();

	Vec2 vPos = GetPos();
	_spriteRenderer->LookAt(dir);
	SetPos(vPos);
}

void Player::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();

	int width = m_pTex->GetWidth();
	int height = m_pTex->GetHeight();

	ComponentRender(_hdc);
}

void Player::Parry()
{
	if (prevParryTime + parryingTime + parryCoolTime > TIME || isParrying) return;
	prevParryTime = TIME;
	isParrying = true;
}

void Player::Parrying()
{
	if (prevParryTime + parryingTime < TIME || !isParrying)
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
		proj->SetDir(proj->GetDir() * -1);
		parried = true;
	}

	if (parried) isParrying = false;
}
