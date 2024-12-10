#include "pch.h"
#include <format>
#include "GameCanvas.h"
#include "Image.h"
#include "Text.h"
#include "Button.h"
#include "Slider.h"
#include "Player.h"
#include "Action.h"
#include "PlayerHealthCompo.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "SkillManager.h"
#include "XPManager.h"
#include "DashSkill.h"
#include "StageLoader.h"

GameCanvas::GameCanvas() :
	healthBar(nullptr),
	shieldBar(nullptr),
	attackCountBar(nullptr),
	floorText(nullptr),
	timeText(nullptr)
{
	SetName(L"GameCanvas");
	GET_SINGLE(XPManager)->Init();
	int offset = 30;
	Player* player = static_cast<Player*>(FindObject(L"Player", LAYER::PLAYER));
	PlayerHealthCompo* playerHealthCompo = player->GetComponent<PlayerHealthCompo>();

	//BottomHeathContainer
	{
		Vec2 size = { 400.f - offset/2, 125.f - offset };
		Vec2 pos = { (size.x / 2) + offset / 2, (SCREEN_HEIGHT - size.y / 2) - offset/2 };

		Image* BottomHeathContainer = CreateUI<Image>(pos, size);
		BottomHeathContainer->texture = LOADTEXTURE(L"UISprite4X1", L"Texture\\UISprite4X1.bmp");

		//HealthBar
		{
			//HealthText
			{
				healthText = CreateUI<Text>({ pos.x, pos.y - offset / 2 }, { (int)size.x - offset, 45});

				healthText->LoadFont(L"PF스타더스트", 12, 15);
				healthText->SetText(L"HP : 100%");
				healthText->SetColor(RGB(15, 56, 15));
				healthText->SetPitchAndFamily(DT_LEFT);

				playerHealthCompo->ChangeHpEvent +=
					[ct = healthText](float value)
					{
						std::wstring wstr;
						ct->SetText(L"HP : " + std::to_wstring((int)(value * 100.f)) + L"%");
					};
			}

			healthBar = CreateUI<Slider>(healthText->GetPos(), { size.x - offset, 45.f- offset });

			player->GetComponent<HealthCompo>()->ChangeHpEvent += 
				[ct = healthBar](float value) 
				{ 
					ct->SetValue(value); 
				};
		}

		//ShieldBar
		{
			//ShieldText
			{
				shieldText = CreateUI<Text>({ pos.x, pos.y + offset*0.9f }, { (int)size.x - offset, 45 });

				shieldText->LoadFont(L"PF스타더스트", 12, 15);
				shieldText->SetText(L"SHIELD : 100%");
				shieldText->SetColor(RGB(15, 56, 15));
				shieldText->SetPitchAndFamily(DT_LEFT);

				playerHealthCompo->ChangeSubHpEvent +=
					[ct = shieldText](float value)
					{
						std::wstring wstr;
						ct->SetText(L"SHIELD : " + std::to_wstring((int)(value * 100.f)) + L"%");
					};
			}

			shieldBar = CreateUI<Slider>(shieldText->GetPos(), { size.x - offset, 45.f- offset });

			player->GetComponent<PlayerHealthCompo>()->ChangeSubHpEvent +=
				[ct = shieldBar](float value)
				{
					ct->SetValue(value);
				};
		}
	}

	//BottomAttackCountContainer
	{
		Vec2 size = { 62.5f - offset / 2, 125.f - offset };
		Vec2 pos = { 400 + offset, (int)(SCREEN_HEIGHT - size.y / 2 - offset/2) };

		Image* BottomHeathContainer = CreateUI<Image>(pos, size);
		BottomHeathContainer->texture = LOADTEXTURE(L"UISprite1X2", L"Texture\\UISprite1X2.bmp");

		//AttackCountBar
		{
			attackCountBar = CreateUI<Slider>(pos, { size.x-offset, size.y-offset });

			attackCountBar->isVertical = true;
			attackCountBar->flip = true;

			player->ParryCoolTimeEvent +=
				[ct = attackCountBar](float value) 
				{
					ct->SetValue(value);
				};
		}
	}

	//BottomDashCoolTimeContainer
	{
		Vec2 size = { 62.5f - offset / 2, 125.f - offset };
		Vec2 pos = { 400 + offset + (int)size.x + offset / 4, (int)(SCREEN_HEIGHT - size.y / 2 - offset / 2) };

		bottomDashCoolTimeContainer = CreateUI<Image>(pos, size);
		bottomDashCoolTimeContainer->texture = LOADTEXTURE(L"UISprite1X2", L"Texture\\UISprite1X2.bmp");


		//DashCoolTimeBar
		{
			dashCoolTimeBar = CreateUI<Slider>( pos, { size.x - offset, size.y - offset });

			dashCoolTimeBar->isVertical = true;
			dashCoolTimeBar->flip = true;

			DashSkill* dashSkill = static_cast<DashSkill*>(GET_SINGLE(SkillManager)->GetSkill(ESkillType::DashSkill));
			dashSkill->DelayTimeEvent +=
				[ct = dashCoolTimeBar](float value)
				{
					ct->SetValue(value);
				};
		}

		bottomDashCoolTimeContainer->SetActive(false);
		dashCoolTimeBar->SetActive(false);
	}

	//floorText
	{
		{
			Vec2 size = { 70, 70 };
			Vec2 pos = { SCREEN_WIDTH / 2, (int)size.y / 2 + 15 };
			Image* floorText = CreateUI<Image>(pos, size);
			floorText->texture = LOADTEXTURE(L"UISprite1X1", L"Texture\\UISprite1X1.bmp");
		}

		Vec2 size = { 50, 60 };
		Vec2 pos = { SCREEN_WIDTH / 2, (int)size.y/2+ 25 };

		floorText = CreateUI<Text>(pos, size);
		floorText->LoadFont(L"PF스타더스트 Bold", 40, 55);
		floorText->SetText(L"1");

		floorText->SetColor(RGB(15, 56, 15));
		floorText->SetPitchAndFamily(DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		StageLoader::StageLoadEvent.Clear();

		StageLoader::StageLoadEvent +=
			[ct = floorText](int stage)
			{
				ct->SetText(std::to_wstring(stage+1));
			};

	}

	//TimeText
	{
		Vec2 size = { 80, 30 };
		Vec2 pos = { SCREEN_WIDTH - (int)size.x/2,  offset };
		timeText = CreateUI<Text>(pos, size);

		timeText->LoadFont(L"PF스타더스트", 18, 24);
		timeText->SetText(L"00:00");
		timeText->SetColor(RGB(139, 172, 15));
		timeText->SetPitchAndFamily(DT_LEFT);
	}

	//XPBar
	{
		Vec2 size = {SCREEN_WIDTH, 10};
		Vec2 pos = { SCREEN_WIDTH / 2.f, SCREEN_HEIGHT - size.y / 2 };
		xpBar = CreateUI<Slider>(pos, size);
		xpBar->offsetX = 0;
		xpBar->offsetY = 0;
		xpBar->SetValue(0.f);
		GET_SINGLE(XPManager)->IncreaseXPEvent +=
			[ct = xpBar](float value) {
				ct->SetValue(value);
			};
	}
}

GameCanvas::~GameCanvas()
{
}

void GameCanvas::Update()
{
	Canvas::Update();
	if (isMoveToNextStage)
	{
		int speed = 400;
		if (_isMoveToUp)
		{
			Vec2 delta = { 0.f,-fUNSCALEDDT * speed };
			AddPos(delta);
			if (GetPos().y <= _minOffset)
			{
				_isMoveToUp = false;
			}
		}
		else
		{
			Vec2 delta = { 0.f,fUNSCALEDDT * speed };
			AddPos(delta);
			if (GetPos().y >= 0)
			{
				_isMoveToUp = true;
				isMoveToNextStage = false;
				Vec2 origin = { 0, 0 };
				SetPos(origin);
			}
		}
	}

	int s = (int)TIME%60;
	int m = (TIME / 60);

	std::string finalStr = std::format("{0:02}:{1:02}", m, s);
	wstring message_w;
	timeText->SetText(message_w.assign(finalStr.begin(), finalStr.end()).c_str());
}

void GameCanvas::LateUpdate()
{
	Canvas::LateUpdate();

}

void GameCanvas::Render(HDC hdc)
{
	Canvas::Render(hdc);
}

void GameCanvas::ShowDashUI()
{
	dashCoolTimeBar->SetActive(true);
	bottomDashCoolTimeContainer->SetActive(true);
}
