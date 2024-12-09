#include "pch.h"
#include "RazerPatern.h"
#include "TimeManager.h"
#include "Razer.h"
#include "AttackCompo.h"

RazerPatern::RazerPatern()
{
}

RazerPatern::~RazerPatern()
{
}

void RazerPatern::Update()
{
	if (_isUsingSkill == false) return;

	if (_skillStartTime + _skillTime < TIME)
		_isUsingSkill = false;
}

void RazerPatern::UseSkill()
{
	_skillStartTime = TIME;
	_isUsingSkill = true;
	_owner->GetComponent<AttackCompo>()->TryFireRazer(_skillTime);
}
