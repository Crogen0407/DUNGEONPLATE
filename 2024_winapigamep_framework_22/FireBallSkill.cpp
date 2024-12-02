#include "pch.h"
#include "FireBallSkill.h"
#include "SpriteRenderer.h"
#include "Player.h"
#include "PoolManager.h"
#include <ctime>

FireBallSkill::FireBallSkill()
{
	nameText = L"���̾";
	descriptionText = L"���� 20�� ���� \n������ ���ѳ� \n���ڸ��� ����� �� \n�ִ� ������ ����. \n(���� �� \n�ߵ��մϴ�)";
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
			int count = ct->GetLevel();
			EFireBallModeType fireBallModeType = EFireBallModeType::FireBall_L;
			switch (ct->GetLevel())
			{	
			case 1:
			case 2:
			case 3:
			case 4:
				fireBallModeType = EFireBallModeType::FireBall_S;
				break;
			case 5:
			case 6:
			case 7:
				fireBallModeType = EFireBallModeType::FireBall_M;
				break;
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
		rand(); //�̻��ϰ� ó������ ��� Ư�� ���� ���Ϸ� �ȶ�����...
		ranDir.y = (rand() / static_cast<float>(RAND_MAX)) * 2 - 1.f;
		ranDir.x = (rand() / static_cast<float>(RAND_MAX)) * 2 - 1.f;

		ranDir.Normalize();

		FireBallEffect* fireBallEffect =
			static_cast<FireBallEffect*>(POP(L"FireBallEffect", playerPos));
		fireBallEffect->SetDir(ranDir);
		fireBallEffect->SetMode(fireBallModeType);
	}
}