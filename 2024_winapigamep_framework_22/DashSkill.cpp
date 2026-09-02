#include "pch.h"
#include "DashSkill.h"
#include "InputManager.h"
#include "Player.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "GameCanvas.h"

DashSkill::DashSkill() :
	_player(nullptr)
{
	nameText = L"대쉬";
	descriptionText = L"공격 기능은 없지만 \n회피용으론 아주 \n제격입니다! \n\n(스페이스바으로\n발동합니다)";
	isActiveSkill = true;
	maxDelayTime = 4.f;
	_originMaxDelayTime = maxDelayTime;
}

DashSkill::~DashSkill()
{
}

void DashSkill::OnUse(Player* player)
{
}

void DashSkill::OnLevelUp(Player* player)
{
	Skill::OnLevelUp(player);
	if (_player == nullptr)
	{
		_player = player;
		GameCanvas* canvas = static_cast<GameCanvas*>(player->FindObject(L"GameCanvas", LAYER::UI));
		canvas->ShowDashUI();
	}

	maxDelayTime = _originMaxDelayTime - ((_originMaxDelayTime / 2) * (level / 10.f));
	curDelayTime = maxDelayTime;
}

void DashSkill::Update()
{
	if (curDelayTime < maxDelayTime) {
		curDelayTime += fDT;
		DelayTimeEvent.Invoke(curDelayTime / maxDelayTime);
	}
	else
		_canDash = true;


	if (GET_KEYDOWN(KEY_TYPE::SPACE) && _canDash == true)
	{
		curDelayTime = 0.f;
		_canDash = false;

		OnDash();
	}

	if (_isDashing == true)
	{
		_curDashTime += fDT;
		_prevPos = _player->GetPosition();
		float percent = _curDashTime / _dashTime;

		Vec2 pos = Vec2::Lerp(_playerPos, _playerPos + _dashDir * _dashDistance, percent);
		
		_player->SetPosition(pos);
		if (percent >= 1)
		{
			_isDashing = false;
			_player->SetCanMove(true);
		}
	}
}

void DashSkill::StopDash()
{
	if (_isDashing)
	{
		_isDashing = false;
		_player->SetPosition(_prevPos);
	}
}

void DashSkill::OnDash()
{
	_dashDir = _player->GetLastMoveDirection();
	_playerPos = _player->GetPosition();
	_curDashTime = 0;
	_isDashing = true;
	_player->SetCanMove(false);
}
