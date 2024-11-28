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

GameCanvas::GameCanvas() :
	healthBar(nullptr),
	shieldBar(nullptr),
	attackCountBar(nullptr),
	scoreText(nullptr),
	timeText(nullptr)
{
	int offset = 30;
	Player* player = static_cast<Player*>(FindObject(L"Player", LAYER::PLAYER));
	//BottomHeathContainer
	{
		Vec2 size = { 400.f - offset/2, 125.f - offset };
		Vec2 pos = { (size.x / 2) + offset / 2, (SCREEN_HEIGHT - size.y / 2) - offset/2 };

		Image* BottomHeathContainer = static_cast<Image*>(CreateUI(UIOPTION::IMAGE,
			pos, size));
		BottomHeathContainer->texture = LOADTEXTURE(L"UISprite4X1", L"Texture\\UISprite4X1.bmp");

		AddUI(BottomHeathContainer);

		//HealthBar
		{
			healthBar = static_cast<Slider*>(CreateUI(UIOPTION::SLIDER,
				{ pos.x, pos.y - offset/2 },
				{ size.x - offset*2, 45.f- offset }));

			player->GetComponent<HealthCompo>()->ChangeHpEvent += 
				[ct = healthBar](float value) 
				{ 
					ct->SetValue(value); 
				};

			AddUI(healthBar);
		}

		//ShieldBar
		{
			shieldBar = static_cast<Slider*>(CreateUI(UIOPTION::SLIDER,
				{ pos.x, pos.y + offset/2 },
				{ size.x - offset * 2, 45.f- offset }));

			player->GetComponent<PlayerHealthCompo>()->ChangeSubHpEvent +=
				[ct = shieldBar](float value)
				{
					ct->SetValue(value);
				};

			AddUI(shieldBar);
		}
	}

	//BottomAttackCountContainer
	{
		Vec2 size = { 62.5f - offset / 2, 125.f - offset };
		Vec2 pos = { 400 + offset, (int)(SCREEN_HEIGHT - size.y / 2 - offset/2) };

		Image* BottomHeathContainer = static_cast<Image*>(CreateUI(UIOPTION::IMAGE, pos, size));
		BottomHeathContainer->texture = LOADTEXTURE(L"UISprite1X2", L"Texture\\UISprite1X2.bmp");
		AddUI(BottomHeathContainer);

		//AttackCountBar
		{
			attackCountBar = static_cast<Slider*>(CreateUI(UIOPTION::SLIDER,
				pos, { size.x-offset, size.y-offset }));

			attackCountBar->isVertical = true;
			attackCountBar->flip = true;

			player->ParryCoolTimeEvent +=
				[ct = attackCountBar](float value) 
				{
					ct->SetValue(value);
				};
			AddUI(attackCountBar);
		}
	}

	//ScoreText
	{
		Vec2 size = { 0, 0 };
		Vec2 pos = { SCREEN_WIDTH / 2, 15 };
		scoreText = static_cast<Text*>(CreateUI(UIOPTION::TEXT, pos, size));

		scoreText->LoadFont(L"PF스타더스트", 45, 60);
		scoreText->SetText(L"5");
		scoreText->SetColor(RGB(139, 172, 15));
		scoreText->SetPitchAndFamily(TA_TOP | TA_CENTER);
		AddUI(scoreText);
	}

	//TimeText
	{
		Vec2 size = { 0, 0 };
		Vec2 pos = { 0.1f + offset,  (SCREEN_HEIGHT - 125.f - offset / 2) + offset /2 };
		timeText = static_cast<Text*>(CreateUI(UIOPTION::TEXT, pos, size));

		timeText->LoadFont(L"PF스타더스트", 18, 24);
		timeText->SetColor(RGB(139, 172, 15));
		timeText->SetPitchAndFamily(TA_BOTTOM | TA_LEFT);
		AddUI(timeText);
	}
}

GameCanvas::~GameCanvas()
{
}

void GameCanvas::Update()
{
	Canvas::Update();

	int s = (int)TIME%60;
	int m = (TIME / 60);

	std::string finalStr = std::format("{0:02}:{1:02}", m, s);
	wstring message_w;
	timeText->SetText(message_w.assign(finalStr.begin(), finalStr.end()).c_str());

	if (GET_KEYDOWN(KEY_TYPE::ENTER))
	{
		healthBar->value -= 0.1f;
	}
}

void GameCanvas::LateUpdate()
{
	Canvas::LateUpdate();

}

void GameCanvas::Render(HDC hdc)
{
	Canvas::Render(hdc);
}
