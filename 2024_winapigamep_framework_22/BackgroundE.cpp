#include "pch.h"
#include "BackgroundE.h"
#include "TimeManager.h"

BackgroundE::BackgroundE()
{
	_maxEnemyCount = 1;
	_spawnDelayTime = 15.f;
	_currentTime = _spawnDelayTime;
}

BackgroundE::~BackgroundE()
{
}

void BackgroundE::Update()
{
	_currentTime += fDT;
	if (_currentTime > _spawnDelayTime)
	{
		SpawnEnemyByRandomPos(EnemyType::EnemyE);
		_currentTime = 0.f;
	}
}
