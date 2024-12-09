#include "pch.h"
#include "MissilePatern.h"
#include "GuidedMissile.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "Scene.h"

MissilePatern::MissilePatern()
{

}

MissilePatern::~MissilePatern()
{
}

void MissilePatern::Update()
{
	if (_isUsingSkill == false) return;

	if (_prevShootTime + 0.1f < TIME)
	{
		_prevShootTime = TIME;
		_currentIdx++;

		Vec2 dir[2]{ {-1,-1}, {1,-1} };
		Vec2 pos = _owner->GetPos();
		pos += {0, -50};

		Vec2 curDir = dir[_currentIdx % 2];
		curDir.Normalize();

		GuidedMissile* missile = new GuidedMissile();
		missile->SetPos(pos);
		missile->SetDir(curDir);

		GET_SINGLE(SceneManager)->GetCurrentScene()
			->AddObject(missile, LAYER::PROJECTILE);

		if (_currentIdx == 6)
			_isUsingSkill = false;
	}
}

void MissilePatern::UseSkill()
{
	_isUsingSkill = true;
	_currentIdx = 0;
	_prevShootTime = TIME;
}
