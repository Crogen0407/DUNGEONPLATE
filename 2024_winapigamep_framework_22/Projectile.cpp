#include "pch.h"
#include "Projectile.h"
#include "TimeManager.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Collider.h"
#include "EventManager.h"
#include "HealthCompo.h"
#include "Scene.h"

Projectile::Projectile() : _dir(1.f, 1.f)
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
	LAYER layer =
		GET_SINGLE(SceneManager)->GetCurrentScene()->GetLayer(_other->GetOwner());

	if (layer == LAYER::PLAYER || (layer == LAYER::ENEMY && _hitEnemy))
	{
		HealthCompo* health = _other->GetOwner()->GetComponent<HealthCompo>();

		if (health != nullptr)
			health->ApplyDamage(damage);

		Object* pOtherObj = _other->GetOwner();
		GET_SINGLE(EventManager)->DeleteObject(this);
	}
}

void Projectile::StayCollision(Collider* _other)
{
}

void Projectile::ExitCollision(Collider* _other)
{
}

void Projectile::Parry()
{
	SetDir(GetDir() * -1);
	_hitEnemy = true;
}
