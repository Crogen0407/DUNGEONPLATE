#include "pch.h"
#include "RazerPattern.h"
#include "TimeManager.h"
#include "Razer.h"
#include "AttackCompo.h"
#include "ResourceManager.h"

RazerPatern::RazerPatern()
{
	LOADSOUND(L"laserBeam", L"Sound\\laserBeam.wav", SOUND_CHANNEL::EFFECT3);
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
	PLAY(L"laserBeam");
	_skillStartTime = TIME;
	_isUsingSkill = true;
	_owner->GetComponent<AttackCompo>()->TryFireRazer(_skillTime);
}
