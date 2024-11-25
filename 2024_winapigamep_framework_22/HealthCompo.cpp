#include "pch.h"
#include "HealthCompo.h"

HealthCompo::HealthCompo() :
	hp(100),
	maxHp(100)
{
}

HealthCompo::~HealthCompo()
{
}

void HealthCompo::ApplyDamage(int value)
{
	hp -= value;
	//데미지 이벤트 실행
	if (hp <= 0)
	{
		//죽음 이벤트 실행
	}
}

void HealthCompo::ApplyHeal(int value)
{
	//힐 이벤트 실행
	hp += value;
}
