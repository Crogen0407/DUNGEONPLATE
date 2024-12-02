#include "pch.h"
#include "RazerSkill.h"
#include "TimeManager.h"
#include "Razer.h"
#include "AttackCompo.h"

RazerSkill::RazerSkill()
{
}

RazerSkill::~RazerSkill()
{
}

void RazerSkill::Update()
{
	if (_isUsingSkill == false) return;

	if (_skillStartTime + _skillTime < TIME)
		_isUsingSkill = false;
}

void RazerSkill::UseSkill()
{
	_skillStartTime = TIME;
	_isUsingSkill = true;
	_owner->GetComponent<AttackCompo>()->TryFireRazer(_skillTime);
}
