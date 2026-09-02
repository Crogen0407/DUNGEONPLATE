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
#include "TimeManager.h"
#include "Easings.h"

Enemy::Enemy() : _originHp(5), _isDead(false)
{
	this->AddComponent<Collider>();
	this->AddComponent<HealthCompo>();

	GetComponent<Collider>()->SetSize(Vec2(50, 50));
	GetComponent<HealthCompo>()->DieEvent +=
		[ct = this](int _) { ct->OnDie(); };
	GetComponent<HealthCompo>()->DamagedEvent += [this](float _) 
		{ 
			this->_isHit = true;
			SetSize(_originSize);
		};
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	if (_isHit)
	{
		auto percent = _hitTime / _hitDuration;
		OnHiting(percent);

		_hitTime += GET_SINGLE(TimeManager)->GetDT();
		cout << _hitTime;

		if (percent > 1.f)
		{
			_isHit = false;
			_hitTime = 0.f;
			SetSize(_originSize);
		}
	}
}

void Enemy::OnDie()
{
	ADDXP(_giveExp);
	ExplosionEffect* explosion = new ExplosionEffect(L"ExplosionEffect02");
	explosion->SetPosition(GetPosition());
	ADDOBJECT(explosion, LAYER::EFFECT);
	GET_SINGLE(EventManager)->DeleteObject(this);
}

void Enemy::OnHiting(float percent)
{
	Vec2 size = _originSize * EaseOutCubic(percent);
	SetSize(size);
}