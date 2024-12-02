#include "pch.h"
#include "Enemy.h"
#include "Agent.h"
#include "Collider.h"
#include "EventManager.h"
#include "HealthCompo.h"
#include "XPManager.h"
#include "StageScene.h"
#include "StageManager.h"

Enemy::Enemy() : m_hp(5), m_attack(5)
{
	this->AddComponent<Collider>();
	this->AddComponent<HealthCompo>();

	GetComponent<Collider>()->SetSize(Vec2(100,100));
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
	GET_SINGLE(EventManager)->DeleteObject(this);

	ADDXP(1);

	StageManager::GetInstance()->enemyCount--;
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
