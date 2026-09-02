#include "pch.h"
#include "BackgroundB.h"
#include "TimeManager.h"

BackgroundB::BackgroundB()
{
	_maxEnemyCount = 2;
	_spawnDelayTime = 10.f;
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
