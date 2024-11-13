#include "pch.h"
#include "Projectile.h"
#include "TimeManager.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Collider.h"
#include "EventManager.h"
Projectile::Projectile()
//	: m_dir(-1.f)
	: m_angle(0.f)
	, m_vDir(1.f, 1.f)
{
	//m_pTex = new Texture;
	//wstring path = GET_SINGLE(ResourceManager)->GetResPath();
	//path += L"Texture\\Bullet.bmp";
	//m_pTex->Load(path);
	m_pTex = GET_SINGLE(ResourceManager)->TextureLoad(L"Bullet", L"Texture\\Bullet.bmp");
	this->AddComponent<Collider>();
	GetComponent<Collider>()->SetSize({ 20.f,20.f });
}

Projectile::~Projectile()
{
}

void Projectile::Update()
{
	Vec2 vPos = GetPos();
	// 삼각함수의 단위가 2가지가 있다.
	// 라디안, 디그리
	//vPos.x += cosf(m_angle) * 500.f * fDT;
	//vPos.y += sinf(m_angle) * 500.f * fDT;

	vPos.x += m_vDir.x * 500.f * fDT;
	vPos.y += m_vDir.y * 500.f * fDT;
	SetPos(vPos);
	Vec2 vSize = GetSize();
	if (vPos.y < -vSize.y)
	{
		GET_SINGLE(EventManager)->DeleteObject(this);
	}
}

void Projectile::Render(HDC _hdc)
{
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();
	//ELLIPSE_RENDER(_hdc, vPos.x, vPos.y
	//	, vSize.x, vSize.y);
	int width = m_pTex->GetWidth();
	int height = m_pTex->GetHeight();
	::TransparentBlt(_hdc
		, (int)(vPos.x - width / 2)
		, (int)(vPos.y - height / 2)
		, width, height,
		m_pTex->GetTexDC()
		, 0, 0, width, height, RGB(255, 0, 255));
	ComponentRender(_hdc);
}

void Projectile::EnterCollision(Collider* _other)
{
	Object* pOtherObj = _other->GetOwner();
	if (pOtherObj->GetName() == L"Enemy")
	{
		GET_SINGLE(EventManager)->DeleteObject(this);
	}
}

void Projectile::StayCollision(Collider* _other)
{
}

void Projectile::ExitCollision(Collider* _other)
{
}
