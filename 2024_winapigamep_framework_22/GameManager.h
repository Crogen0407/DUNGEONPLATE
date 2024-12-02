#pragma once
class Player;
class GameManager
{
	DECLARE_SINGLE(GameManager);
public:
	void Init();
	void Update();
	Player* player = nullptr;
};