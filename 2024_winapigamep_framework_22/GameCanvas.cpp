#include "pch.h"
#include "GameCanvas.h"
#include "Image.h"
#include "Text.h"
#include "Button.h"
#include "Slider.h"
#include "ResourceManager.h"
#include "Action.h"
#include "InputManager.h"
#include <iostream>

GameCanvas::GameCanvas()
{
	int offset = 10;

	//BottomHeathContainer
	{
		Vec2 size = { (int)(SCREEN_WIDTH / 7 * 6) - offset/2, (int)(SCREEN_HEIGHT / 8.f) - offset };
		Vec2 pos = { (int)(size.x / 2) + offset / 2, (int)(SCREEN_HEIGHT - size.y / 2) - offset/2 };

		Image* BottomHeathContainer = static_cast<Image*>(UI::CreateUI(UIOPTION::IMAGE,
			pos, size));
		BottomHeathContainer->texture = LOADTEXTURE(L"UISprite2X1", L"Texture\\UISprite2X1.bmp");

		AddUI(BottomHeathContainer);

		//HealthBar
		{
			Slider* healthBar = static_cast<Slider*>(UI::CreateUI(UIOPTION::SLIDER, 
				{ pos.x, pos.y + offset - 35 },
				{ size.x - offset*2, 35.f }));

			healthBar->fillTexture = LOADTEXTURE(L"HealthBar_Fill", L"Texture\\HealthBar_Fill.bmp");
			healthBar->backTexture = LOADTEXTURE(L"UISprite4X1", L"Texture\\UISprite4X1.bmp");

			AddUI(healthBar);
		}

		//ShieldBar
		{
			Slider* shieldBar = static_cast<Slider*>(UI::CreateUI(UIOPTION::SLIDER,
				{ pos.x, pos.y + offset + 15 },
				{ size.x - offset * 2, 35.f }));

			shieldBar->fillTexture = LOADTEXTURE(L"ShieldBar_Fill", L"Texture\\ShieldBar_Fill.bmp");
			shieldBar->backTexture = LOADTEXTURE(L"UISprite4X1", L"Texture\\UISprite4X1.bmp");

			shieldBar->value = 0.5f;

			AddUI(shieldBar);
		}
	}

	//BottomAttackCountContainer
	{
		Vec2 size = { (int)((SCREEN_WIDTH / 7) - offset / 2), (int)(SCREEN_HEIGHT / 8.f) - offset };
		Vec2 pos = { SCREEN_WIDTH - (int)(size.x / 2) - offset / 2, (int)(SCREEN_HEIGHT - size.y / 2 - offset/2) };

		Image* BottomHeathContainer = static_cast<Image*>(UI::CreateUI(UIOPTION::IMAGE, pos, size));
		BottomHeathContainer->texture = LOADTEXTURE(L"UISprite", L"Texture\\UISprite.bmp");
		AddUI(BottomHeathContainer);

		//AttackCountSlider
		{
			Slider* attackCountSlider = static_cast<Slider*>(UI::CreateUI(UIOPTION::SLIDER,
				pos, { size.x - offset * 2, size.y-offset*2 }));

			attackCountSlider->isVertical = true;
			attackCountSlider->fillTexture = LOADTEXTURE(L"AttackBar_Fill", L"Texture\\AttackBar_Fill.bmp");
			attackCountSlider->backTexture = LOADTEXTURE(L"UISprite", L"Texture\\UISprite.bmp");

			attackCountSlider->value = 0.75f;
			attackCountSlider->flip = true;
			AddUI(attackCountSlider);
		}
	}

	//ScoreText
	{
		Vec2 size = { 0, 0 };
		Vec2 pos = { SCREEN_WIDTH / 2, 15 };
		Text* scoreText = static_cast<Text*>(UI::CreateUI(UIOPTION::TEXT, pos, size));

		scoreText->LoadFont(L"엘리스 DX널리체 Bold", 45, 60);
		scoreText->SetText(L"5");
		scoreText->SetPitchAndFamily(TA_TOP | TA_CENTER);
		AddUI(scoreText);
	}

	//TimeText
	{
		Vec2 size = { 0, 0 };
		Vec2 pos = { offset, (int)(SCREEN_HEIGHT - (SCREEN_HEIGHT / 8.f) - offset/2) };
		Text* timeText = static_cast<Text*>(UI::CreateUI(UIOPTION::TEXT, pos, size));

		timeText->LoadFont(L"엘리스 DX널리체 Bold", 18, 24);
		timeText->SetText(L"00:00");
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
}

void GameCanvas::LateUpdate()
{
	Canvas::LateUpdate();

}

void GameCanvas::Render(HDC hdc)
{
	Canvas::Render(hdc);
}
