#include "pch.h"
#include "Projectile.h"
#include "TimeManager.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Collider.h"
#include "EventManager.h"

Projectile::Projectile() : _dir(1.f, 1.f), _canParry(true)
{
	//m_pTex = new Texture;
	//wstring path = GET_SINGLE(ResourceManager)->GetResPath();
	//path += L"Texture\\Bullet.bmp";
	//m_pTex->Load(path);

	
}

Projectile::~Projectile()
{
}

//void Projectile::Update()
//{
//	Vec2 vPos = GetPos();
//
//	vPos.x += m_vDir.x * speed * fDT;
//	vPos.y += m_vDir.y * speed * fDT;
//	SetPos(vPos);
//	Vec2 vSize = GetSize();
//	if (vPos.y < -vSize.y)
//	{
//		GET_SINGLE(EventManager)->DeleteObject(this);
//	}
//}

//void Projectile::Render(HDC _hdc)
//{
//	Vec2 vPos = GetPos();
//	Vec2 vSize = GetSize();
//
//	int width = m_pTex->GetWidth();
//	int height = m_pTex->GetHeight();
//	::TransparentBlt(_hdc
//		, (int)(vPos.x - width / 2)
//		, (int)(vPos.y - height / 2)
//		, width, height,
//		m_pTex->GetTexDC()
//		, 0, 0, width, height, RGB(255, 0, 255));
//	ComponentRender(_hdc);
//}

void Projectile::EnterCollision(Collider* _other)
{
	Object* pOtherObj = _other->GetOwner();
	GET_SINGLE(EventManager)->DeleteObject(this);
}

void Projectile::StayCollision(Collider* _other)
{
}

void Projectile::ExitCollision(Collider* _other)
{
}
