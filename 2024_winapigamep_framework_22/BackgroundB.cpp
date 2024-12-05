#include "pch.h"
#include "BackgroundB.h"
#include "TimeManager.h"

BackgroundB::BackgroundB()
{
	_currentSpawnedEnemyCount = 1;
	_spawnDelayTime = 100.f;
	_currentTime = _spawnDelayTime;
}

BackgroundB::~BackgroundB()
{
}

void BackgroundB::Update()
{
	_currentTime += fDT;
	if (_currentTime > _spawnDelayTime)
	{
		SpawnEnemyByRandomPos(EnemyType::EnemyB);
		_currentTime = 0.f;
	}
}
