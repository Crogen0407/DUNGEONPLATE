#include "pch.h"
#include "Boss.h"
#include "TimeManager.h"
#include "MissileSkill.h"
#include "HealthCompo.h"
#include "Collider.h"
#include "ResourceManager.h"
#include "Animator.h"
#include "Texture.h"
#include "EnemyPaternA.h"
#include "AttackCompo.h"
#include "RazerSkill.h"
#include "BounceBulletSkill.h"

Boss::Boss() : _currentSkill{ nullptr }
{
	SetSize({ 100,100 });
	texture = LOADTEXTURE(L"Boss", L"Texture\\Enemy03.bmp");
	Vec2 texSize = { (int)texture->GetWidth() / 6, (int)texture->GetHeight() };
	AddComponent< Collider>();
	AddComponent<HealthCompo>();
	AddComponent<Animator>();
	AddComponent<AttackCompo>();

	GetComponent<Collider>()->SetSize({ 100,100 });
	GetComponent<HealthCompo>()->SetOffsetY(50);
	GetComponent<Animator>()->CreateAnimation(L"Boss", texture, { 0,0 }, texSize, { (int)texSize.x, 0 }, 6, 0.2f, false);
	GetComponent<Animator>()->PlayAnimation(L"Boss", true, 100);

	_prevSkillTime = TIME;
	MissileSkill* mSkill = new MissileSkill();
	mSkill->SetOwner(this);
	EnemyPaternA* paternA = new EnemyPaternA();
	paternA->SetOwner(this);
	RazerSkill* razerSkill = new RazerSkill();
	razerSkill->SetOwner(this);
	BounceBulletSkill* bounceBulletSkill = new BounceBulletSkill();
	bounceBulletSkill->SetOwner(this);

	_skills.push_back(mSkill);
	_skills.push_back(paternA);
	_skills.push_back(razerSkill);
	_skills.push_back(bounceBulletSkill);
}

Boss::~Boss()
{
	//스킬을 new로 할당해줬기 때문에 사라질 때 함께 사라지는
	for (auto skill : _skills)
		delete(skill);
}

void Boss::Update()
{
	if (_currentSkill != nullptr)
	{
		_currentSkill->Update();

		if (_currentSkill->IsUsingSkill() == false)
			_currentSkill = nullptr;
	}
	else
	{
		if (_prevSkillTime + _skillCoolTime < TIME)
		{
			_prevSkillTime = TIME;

			int idx = rand() % _skills.size();
			_skills[idx]->UseSkill();
			_currentSkill = _skills[idx];
		}
	}
}

void Boss::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}
