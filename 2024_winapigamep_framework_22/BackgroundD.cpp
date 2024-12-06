#include "pch.h"
#include "BackgroundD.h"
#include "TimeManager.h"

BackgroundD::BackgroundD()
{
	_maxEnemyCount = 2;
	_spawnDelayTime = 10.f;
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
