#include "pch.h"
#include "Enemy.h"
#include "Agent.h"
#include "Collider.h"
#include "EventManager.h"
#include "PoolManager.h"
#include "HealthCompo.h"
#include "XPManager.h"
#include "StageScene.h"
#include "StageLoader.h"
#include "Movement.h"
#include "ExplosionEffect.h"
#include "SceneManager.h"

Enemy::Enemy() : _originHp(5), m_attack(5), _isDead(false)
{
	this->AddComponent<Collider>();
	this->AddComponent<HealthCompo>();

	GetComponent<Collider>()->SetSize(Vec2(50,50));
	GetComponent<HealthCompo>()->DieEvent += 
		[ct = this](int _) 
		{
			ct->OnDie();
		};
}

Enemy::~Enemy()
{
}

void Enemy::OnDie()
{
	ADDXP(1);
	//StageLoader::GetInstance()->enemyCount--;
	ExplosionEffect* explosion = new ExplosionEffect(L"ExplosionEffect02");
	explosion->SetPos(GetPos());
	ADDOBJECT(explosion, LAYER::SCREENEFFECT);
	GET_SINGLE(EventManager)->DeleteObject(this);
	
	//_isDead = true;
	/*_rotation = 0;
	_knockDir = GetPos();
	_knockDir -= _target->GetPos();
	_knockDir.Normalize();*/
}

void Enemy::EnterCollision(Collider* _other)
{
	/*Object* pOtherObj = _other->GetOwner();
	wstring str = pOtherObj->GetName();*/

	//¸Â´Â°Å
	/*if (pOtherObj->GetName() == L"PlayerBullet")
	{
		m_hp -= 1;
		if(m_hp <=0)
			GET_SINGLE(EventManager)->DeleteObject(this);
	}*/
}

void Enemy::StayCollision(Collider* _other)
{
	//std::cout << "Stay" << std::endl;
}

void Enemy::ExitCollision(Collider* _other)
{

}
