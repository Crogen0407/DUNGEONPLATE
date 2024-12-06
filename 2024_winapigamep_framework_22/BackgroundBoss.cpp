#include "pch.h"
#include "BackgroundBoss.h"
#include "TimeManager.h"

BackgroundBoss::BackgroundBoss()
{
	_maxEnemyCount = 1;
	_spawnDelayTime = 1000.f;
	_currentTime = _spawnDelayTime;
}

BackgroundBoss::~BackgroundBoss()
{
}

void BackgroundBoss::Update()
{
	_currentTime += fDT;
	if (_currentTime > _spawnDelayTime)
	{
		SpawnEnemyByRandomPos(EnemyType::Boss);
		_currentTime = 0;
	}
}
