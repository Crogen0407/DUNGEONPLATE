#include "pch.h"
#include "BackgroundD.h"
#include "TimeManager.h"

BackgroundD::BackgroundD()
{
	_currentEnemyCount = 1;
	_spawnDelayTime = 100.f;
	_currentTime = _spawnDelayTime;
}

BackgroundD::~BackgroundD()
{
}

void BackgroundD::Update()
{
	_currentTime += fDT;
	if (_currentTime > _spawnDelayTime)
	{
		SpawnEnemyByRandomPos(EnemyType::EnemyD);
		_currentTime = 0.f;
	}
}
