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
	AddComponent<Animator>();
	GetComponent<Animator>()->CreateAnimation(L"JiwooFront", m_pTex, Vec2(0.f, 150.f),
		Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.1f);
	GetComponent<Animator>()->PlayAnimation(L"JiwooFront", true);

}
Player::~Player()
{

}
void Player::Update()
{
	if (GET_KEY(KEY_TYPE::W))
		Move(Vec2(0, -1) * speed * fDT);
	if (GET_KEY(KEY_TYPE::S))
		Move(Vec2(0, 1) * speed * fDT);
	if (GET_KEY(KEY_TYPE::A))
		Move(Vec2(-1, 0) * speed * fDT);
	if (GET_KEY(KEY_TYPE::D))
		Move(Vec2(1, 0) * speed * fDT);

	Vec2 vPos = GetPos();

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

}
