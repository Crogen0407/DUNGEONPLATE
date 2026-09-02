#include "pch.h"
#include "BackgroundG.h"
#include "TimeManager.h"

BackgroundG::BackgroundG()
{
	_maxEnemyCount = 1;
	_spawnDelayTime = 10.f;
	_currentTime = _spawnDelayTime;
}

BackgroundG::~BackgroundG()
{
}

void BackgroundG::Update()
{
	_currentTime += fDT;
	if (_currentTime > _spawnDelayTime)
	{
		SpawnEnemyByRandomPos(EnemyType::EnemyF);
		_currentTime = 0.f;
	}
}
