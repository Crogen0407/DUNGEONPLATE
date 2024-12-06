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

Enemy::Enemy() : _originHp(5), _isDead(false)
{
	this->AddComponent<Collider>();
	this->AddComponent<HealthCompo>();

	GetComponent<Collider>()->SetSize(Vec2(50, 50));
	GetComponent<HealthCompo>()->DieEvent +=
		[ct = this](int _) { ct->OnDie(); };
}

Enemy::~Enemy()
{
}

void Enemy::OnDie()
{
	ADDXP(_giveExp);
	ExplosionEffect* explosion = new ExplosionEffect(L"ExplosionEffect02");
	explosion->SetPos(GetPos());
	ADDOBJECT(explosion, LAYER::SCREENEFFECT);
	GET_SINGLE(EventManager)->DeleteObject(this);
}
