#include "pch.h"
#include "GameOverCanvas.h"
#include "Image.h"
#include "Text.h"
#include "Button.h"
#include "Slider.h"
#include "Player.h"
#include "Action.h"
#include "ResourceManager.h"
#include "FadeManager.h"

GameOverCanvas::GameOverCanvas()
{
	//BackGround
	{
		Vec2 size = { SCREEN_WIDTH, SCREEN_HEIGHT };
		Vec2 pos = { size.x * 0.5f, size.y * 0.5f };
		Image* background = CreateUI<Image>(pos, size);
		background->texture = LOADTEXTURE(L"GameOver", L"Texture\\GameOver.png");
	}

	//TitleText
	{
		Vec2 size = { SCREEN_WIDTH, SCREEN_HEIGHT };
		Vec2 pos = { size.x*0.5f, size.y * 0.3f };
		_titleText = CreateUI<Text>(pos, size);
		_titleText->SetText(L"FAIL...");
		_titleText->SetWeight(DWRITE_FONT_WEIGHT_BOLD);
		_titleText->LoadFont(L"PFstardust", 60);
		_titleText->SetPitchAndFamily(DWRITE_TEXT_ALIGNMENT_CENTER);
		_titleText->SetColor(0x9bbc0f);
	}

	//MentText
	{
		Vec2 size = { SCREEN_WIDTH, SCREEN_HEIGHT };
		Vec2 pos = { size.x * 0.5f, size.y * 0.4f };
		_mentText = CreateUI<Text>(pos, size);
		_mentText->SetText(L"가끔은 실패할 수도 있는 겁니다");
		_mentText->LoadFont(L"PFstardust", 20);
		_mentText->SetPitchAndFamily(DWRITE_TEXT_ALIGNMENT_CENTER);
		_mentText->SetColor(0x9bbc0f);
	}

	//RetryButton
	{
		Vec2 size = { 400, 50 };
		Vec2 selectedSize = { 405, 55 };
		Vec2 pos = { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f };
		_retryButton = CreateUI<Button>(pos, size);
		_retryButton->texture = LOADTEXTURE(L"UISprite1X1", L"Texture\\UISprite1X1.png");
		_retryButton->onlyOneCountClick = true;
		_retryButton->OnClickEvent +=
			[](int _)
			{
				GET_MANAGER(FadeManager)->LoadScene(L"GameScene");
			};
		_retryButton->OnSelectEnterEvent +=
			[ct = _retryButton, selectedSize = selectedSize](int _)
			{
				ct->AddPosition({ 0, -2 });
				ct->SetSize(selectedSize);
			};
		_retryButton->OnSelectExitEvent +=
			[ct = _retryButton, size = size](int _)
			{
				ct->AddPosition({ 0, 2 });
				ct->SetSize(size);
			};
		//RetryButtonText
		{
			Text* retryButtonText = CreateUI<Text>(pos, size);
			retryButtonText->SetText(L"RETRY");
			retryButtonText->SetWeight(DWRITE_FONT_WEIGHT_BOLD);
			retryButtonText->LoadFont(L"PFstardust", 18);
			retryButtonText->SetPitchAndFamily(DWRITE_TEXT_ALIGNMENT_CENTER);
			retryButtonText->SetColor(RGB(15, 56, 15));
		}
	}

	//GotoTitleSceneButton
	{
		Vec2 size = { 400, 50 };
		Vec2 selectedSize = { 405, 55 };
		Vec2 pos = { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.57f };
		_gotoTitleSceneButton = CreateUI<Button>(pos, size);
		_gotoTitleSceneButton->texture = LOADTEXTURE(L"UISprite1X1", L"Texture\\UISprite1X1.png");
		_gotoTitleSceneButton->onlyOneCountClick = true;
		_gotoTitleSceneButton->OnClickEvent +=
			[](int _)
			{
				GET_MANAGER(FadeManager)->LoadScene(L"GameScene");
			};
		_gotoTitleSceneButton->OnSelectEnterEvent +=
			[ct = _gotoTitleSceneButton, selectedSize = selectedSize](int _)
			{
				ct->AddPosition({ 0, -2 });
				ct->SetSize(selectedSize);
			};
		_gotoTitleSceneButton->OnSelectExitEvent +=
			[ct = _gotoTitleSceneButton, size = size](int _)
			{
				ct->AddPosition({ 0, 2 });
				ct->SetSize(size);
			};
		//GotoTitleButtonText
		{
			Text* gotoTitleButtonText = CreateUI<Text>(pos, size);
			gotoTitleButtonText->SetText(L"GOTOTITLE");
			gotoTitleButtonText->SetWeight(DWRITE_FONT_WEIGHT_BOLD);
			gotoTitleButtonText->LoadFont(L"PFstardust", 18);
			gotoTitleButtonText->SetPitchAndFamily(DWRITE_TEXT_ALIGNMENT_CENTER);
			gotoTitleButtonText->SetColor(RGB(15, 56, 15));
		}
	}
}

GameOverCanvas::~GameOverCanvas()
{
}
