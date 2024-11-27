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
	int offset = 10;
	Player* player = static_cast<Player*>(FindObject(L"Player", LAYER::PLAYER));

	//BottomHeathContainer
	{
		Vec2 size = { (int)(SCREEN_WIDTH / 7 * 6) - offset/2, (int)(SCREEN_HEIGHT / 8.f) - offset };
		Vec2 pos = { (int)(size.x / 2) + offset / 2, (int)(SCREEN_HEIGHT - size.y / 2) - offset/2 };

		Image* BottomHeathContainer = static_cast<Image*>(UI::CreateUI(UIOPTION::IMAGE,
			pos, size));
		BottomHeathContainer->texture = LOADTEXTURE(L"UISprite4X1", L"Texture\\UISprite4X1.bmp");

		AddUI(BottomHeathContainer);

		//HealthBar
		{
			healthBar = static_cast<Slider*>(UI::CreateUI(UIOPTION::SLIDER,
				{ pos.x, pos.y + offset - 35 },
				{ size.x - offset*2, 35.f }));
			healthBar->fillTexture = LOADTEXTURE(L"HealthBar_Fill", L"Texture\\HealthBar_Fill.bmp");
			healthBar->backTexture = LOADTEXTURE(L"UISprite4X1", L"Texture\\UISprite4X1.bmp");

			player->GetComponent<HealthCompo>()->ChangeHpEvent += 
				[ct = healthBar](float value) 
				{ 
					ct->SetValue(value); 
				};

			AddUI(healthBar);
		}

		//ShieldBar
		{
			shieldBar = static_cast<Slider*>(UI::CreateUI(UIOPTION::SLIDER,
				{ pos.x, pos.y + offset + 15 },
				{ size.x - offset * 2, 35.f }));

			shieldBar->fillTexture = LOADTEXTURE(L"ShieldBar_Fill", L"Texture\\ShieldBar_Fill.bmp");
			shieldBar->backTexture = LOADTEXTURE(L"UISprite4X1", L"Texture\\UISprite4X1.bmp");

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
		Vec2 size = { (int)((SCREEN_WIDTH / 7) - offset / 2), (int)(SCREEN_HEIGHT / 8.f) - offset };
		Vec2 pos = { SCREEN_WIDTH - (int)(size.x / 2) - offset / 2, (int)(SCREEN_HEIGHT - size.y / 2 - offset/2) };

		Image* BottomHeathContainer = static_cast<Image*>(UI::CreateUI(UIOPTION::IMAGE, pos, size));
		BottomHeathContainer->texture = LOADTEXTURE(L"UISprite1X2", L"Texture\\UISprite1X2.bmp");
		AddUI(BottomHeathContainer);

		//AttackCountBar
		{
			attackCountBar = static_cast<Slider*>(UI::CreateUI(UIOPTION::SLIDER,
				pos, { size.x - offset * 2, size.y-offset*2 }));

			attackCountBar->isVertical = true;
			attackCountBar->fillTexture = LOADTEXTURE(L"AttackBar_Fill", L"Texture\\AttackBar_Fill.bmp");
			attackCountBar->backTexture = LOADTEXTURE(L"UISprite", L"Texture\\UISprite.bmp");

			attackCountBar->value = 0.75f;
			attackCountBar->flip = true;
			AddUI(attackCountBar);
		}
	}

	//ScoreText
	{
		Vec2 size = { 0, 0 };
		Vec2 pos = { SCREEN_WIDTH / 2, 15 };
		scoreText = static_cast<Text*>(UI::CreateUI(UIOPTION::TEXT, pos, size));

		scoreText->LoadFont(L"엘리스 DX널리체 Bold", 45, 60);
		scoreText->SetText(L"5");
		scoreText->SetPitchAndFamily(TA_TOP | TA_CENTER);
		AddUI(scoreText);
	}

	//TimeText
	{
		Vec2 size = { 0, 0 };
		Vec2 pos = { offset, (int)(SCREEN_HEIGHT - (SCREEN_HEIGHT / 8.f) - offset/2) };
		timeText = static_cast<Text*>(UI::CreateUI(UIOPTION::TEXT, pos, size));

		timeText->LoadFont(L"엘리스 DX널리체 Bold", 18, 24);
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
