#include "pch.h"
#include "BackgroundNull.h"

BackgroundNull::BackgroundNull()
{
	_maxEnemyCount = 0;
	_currentTime = _spawnDelayTime;
	isClear = true;
}

BackgroundNull::~BackgroundNull()
{
}

void BackgroundNull::Update()
{
}