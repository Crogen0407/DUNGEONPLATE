#include "pch.h"
#include "BombPattern.h"
#include "PlayerManager.h"
#include "TimeManager.h"
#include "Player.h"
#include "EnemyBomb.h"
#include "PoolManager.h"

BombPattern::BombPattern()
{
	_player = GET_SINGLE(PlayerManager)->player;
}

BombPattern::~BombPattern()
{
}

void BombPattern::Update()
{
	if (_isUsingSkill == false) return;

	_curDelayTime += fDT;
	Vec2 playerDir =
	{
		_player->GetPosition().x - _owner->GetPosition().x,
		_player->GetPosition().y - _owner->GetPosition().y
	};

	if (_curDelayTime > _bombMaxCount)
	{
		_curDelayTime = 0.f;

		float angleRange = 120.f * Deg2Rad;
		int count = 10;
		for (int i = 0; i < count; i++)
		{
			float halfAngle = angleRange * ((float)i/count);

			Vec2 dir = playerDir;
			float finalAngle = halfAngle - angleRange / 2;
			dir.x = dir.x * cosf(finalAngle) - dir.y * sinf(finalAngle);
			dir.y = dir.x * sinf(finalAngle) + dir.y * cosf(finalAngle);
			dir.Normalize();
			Vec2 pos = _owner->GetPosition();
			pos += dir * 30;
			auto enemyBomb = static_cast<EnemyBomb*>(POP(L"EnemyBomb", pos));

			enemyBomb->SetMoveDirection(dir);
		}

		if (++_curBombMaxCount >= _bombMaxCount)
			_isUsingSkill = false;
	}
}

void BombPattern::UseSkill()
{
	_isUsingSkill = true;
	_curBombMaxCount = 0.f;
}
