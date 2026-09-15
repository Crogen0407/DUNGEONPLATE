#pragma once
class Player;
class PlayerManager
{
	DECLARE_SINGLE(PlayerManager);
public:
	Player* player = nullptr;
};