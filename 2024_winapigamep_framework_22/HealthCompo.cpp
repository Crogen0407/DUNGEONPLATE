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
	//������ �̺�Ʈ ����
	if (hp <= 0)
	{
		//���� �̺�Ʈ ����
	}
}

void HealthCompo::ApplyHeal(int value)
{
	//�� �̺�Ʈ ����
	hp += value;
}
