#include "pch.h"
#include "BackgroundF.h"
#include "TimeManager.h"

BackgroundF::BackgroundF()
{
	_maxEnemyCount = 1;
	_spawnDelayTime = 10.f;
	_currentTime = _spawnDelayTime;
}

BackgroundF::~BackgroundF()
{
}

void BackgroundF::Update()
{
	_currentTime += fDT;
	if (_currentTime > _spawnDelayTime)
		SpawnEnemyByRandomPos(EnemyType::EnemyA);
}
