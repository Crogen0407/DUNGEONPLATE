#include "pch.h"
#include "Enemy.h"
#include "Agent.h"
#include "Collider.h"
#include "EventManager.h"

Enemy::Enemy() : m_hp(5), m_attack(5)
{
	this->AddComponent<Collider>();
	GetComponent<Collider>()->SetSize(Vec2(100,100));
}

Enemy::~Enemy()
{
}

void Enemy::EnterCollision(Collider* _other)
{
	std::cout << "Enter" << std::endl;
	Object* pOtherObj = _other->GetOwner();
	wstring str = pOtherObj->GetName();
	if (pOtherObj->GetName() == L"PlayerBullet")
	{
		m_hp -= 1;
		if(m_hp <=0)
			GET_SINGLE(EventManager)->DeleteObject(this);
	}
}

void Enemy::StayCollision(Collider* _other)
{
	//std::cout << "Stay" << std::endl;
}

void Enemy::ExitCollision(Collider* _other)
{
	std::cout << "Exit" << std::endl;
}
