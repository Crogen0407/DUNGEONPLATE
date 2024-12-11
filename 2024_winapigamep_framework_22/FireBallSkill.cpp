#include "pch.h"
#include "FireBallSkill.h"
#include "SpriteRenderer.h"
#include "Player.h"
#include "PoolManager.h"
#include <ctime>

FireBallSkill::FireBallSkill()
{
	nameText = L"파이어볼";
	descriptionText = L"무려 20년 동안 \n동정을 지켜낸 \n현자만이 사용할 수 \n있는 전설의 마법. \n(공격 시 발동합니다)";
	isActiveSkill = true;
}

FireBallSkill::~FireBallSkill()
{
}

void FireBallSkill::OnUse(Player* player)
{
}

void FireBallSkill::OnLevelUp(Player* player)
{
	Skill::OnLevelUp(player);
	player->AttackEvent.Clear();
	player->AttackEvent +=
		[ct = this, ctPlayer = player](int _)
		{
			float x = ct->GetLevel() / 10.f;
			int count = (int)((1 - cosf((x * PI) / 2.f)) * 9) + 1;
			EFireBallModeType fireBallModeType = EFireBallModeType::FireBall_L;
			switch (ct->GetLevel())
			{	
			case 1:
			case 2:
				fireBallModeType = EFireBallModeType::FireBall_S;
				break;
			case 3:
			case 4:
			case 5:
				fireBallModeType = EFireBallModeType::FireBall_M;
				break;
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
				fireBallModeType = EFireBallModeType::FireBall_L;
				break;
			}


			ct->Fire(ctPlayer, fireBallModeType, count);
		};
}

void FireBallSkill::Update()
{
}

void FireBallSkill::Fire(Player* player, const EFireBallModeType& fireBallModeType, const int& count)
{
	Vec2 playerPos = player->GetPos();
	for (int i = 0; i < count; i++)
	{
		Vec2 ranDir;

		srand(time(NULL)+i);
		rand(); //이상하게 처음값이 계속 특정 숫자 이하로 안떨어짐...
		ranDir.y = (rand() / static_cast<float>(RAND_MAX)) * 2 - 1.f;
		ranDir.x = (rand() / static_cast<float>(RAND_MAX)) * 2 - 1.f;

		ranDir.Normalize();

		FireBallEffect* fireBallEffect =
			static_cast<FireBallEffect*>(POP(L"FireBallEffect", playerPos));
		fireBallEffect->SetDir(ranDir);
		fireBallEffect->SetMode(fireBallModeType);
	}
}
