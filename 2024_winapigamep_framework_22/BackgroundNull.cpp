#include "pch.h"
#include "BackgroundNull.h"

BackgroundNull::BackgroundNull()
{
	_maxEnemyCount = 0;
	_currentTime = _spawnDelayTime;
}

BackgroundNull::~BackgroundNull()
{
}

void BackgroundNull::Update()
{
}