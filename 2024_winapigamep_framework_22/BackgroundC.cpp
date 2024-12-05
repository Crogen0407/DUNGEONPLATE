#include "pch.h"
#include "BackgroundC.h"
#include "TimeManager.h"

BackgroundC::BackgroundC()
{
	_maxEnemyCount = 1;
	_spawnDelayTime = 100.f;
	_currentTime = _spawnDelayTime;
}

BackgroundC::~BackgroundC()
{
}

void BackgroundC::Update()
{
	_currentTime += fDT;
	if (_currentTime > _spawnDelayTime)
	{
		SpawnEnemyByRandomPos(EnemyType::EnemyC);
		_currentTime = 0.f;
	}
}
