#include "pch.h"
#include "IncreaseMoveSpeedSkill.h"
#include "Player.h"

IncreaseMoveSpeedSkill::IncreaseMoveSpeedSkill()
{
	nameText = L"이동 속도 증가";
	descriptionText = L"우히히!!!\n나는 플래시다!!";
	isActiveSkill = true;
}

IncreaseMoveSpeedSkill::~IncreaseMoveSpeedSkill()
{
}

void IncreaseMoveSpeedSkill::OnUse(Player* player)
{
}

void IncreaseMoveSpeedSkill::OnLevelUp(Player* player)
{
	Skill::OnLevelUp(player);
	if (_playerOriginMoveSpeed == -1)
	{
		_playerOriginMoveSpeed = player->GetMoveSpeed();
		//이펙트 넣기
	}

	_increasePercent += 0.15f;

	player->SetMoveSpeed(_playerOriginMoveSpeed + _playerOriginMoveSpeed * _increasePercent);
}