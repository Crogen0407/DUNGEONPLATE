#include "pch.h"
#include "TitleCanvas.h"
#include "Image.h"
#include "Text.h"
#include "Button.h"
#include "Slider.h"
#include "Player.h"
#include "Action.h"
#include "ResourceManager.h"
#include "FadeManager.h"

TitleCanvas::TitleCanvas()
{
	//Fill
	{
		Vec2 size = { SCREEN_WIDTH, SCREEN_HEIGHT };
		Vec2 pos = { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f };
		Image* fill = CreateUI<Image>(pos, size);
		fill->texture = LOADTEXTURE(L"OnePoint", L"Texture\\OnePoint.png");
	}

	//BackGround
	{
		Vec2 size = { SCREEN_WIDTH/3, SCREEN_HEIGHT/3 };
		Vec2 pos = { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.55f };
		Image* background = CreateUI<Image>(pos, size);
		background->useNineSlice = false;
		background->texture = LOADTEXTURE(L"Background", L"Texture\\Background.png");
	}

	//TitleText
	{
		Vec2 size = { 844, 153 };
		Vec2 pos = {SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT* 0.26f };
		Image* titleText = CreateUI<Image>(pos, size);
		titleText->useNineSlice = false;
		titleText->texture = LOADTEXTURE(L"Title", L"Texture\\Title.png");
	}

	// Buttons
	{
		Vec2 size = { 250, 40 };
		Vec2 selectedSize = { 255, 45 };

		//StartButton
		{
			Vec2 pos = { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.47f };
			_startButton = CreateUI<Button>(pos, size);
			_startButton->texture = LOADTEXTURE(L"UISprite1X1", L"Texture\\UISprite1X1.png");
			_startButton->onlyOneCountClick = true;
			_startButton->OnClickEvent +=
				[](int _)
				{
					GET_SINGLE(FadeManager)->LoadScene(L"GameScene");
				};
			_startButton->OnSelectEnterEvent +=
				[ct = _startButton, selectedSize = selectedSize](int _)
				{
					ct->AddPos({ 0, -2 });
					ct->SetSize(selectedSize);
				};
			_startButton->OnSelectExitEvent +=
				[ct = _startButton, size = size](int _)
				{
					ct->AddPos({ 0, 2 });
					ct->SetSize(size);
				};
			//StartButtonText
			{
				Text* startButtonText = CreateUI<Text>({ 0, 0 }, size);
				startButtonText->SetParent(_startButton);
				startButtonText->SetText(L"START");
				startButtonText->SetWeight(DWRITE_FONT_WEIGHT_BOLD);
				startButtonText->LoadFont(L"PFstardust", 18);
				startButtonText->SetPitchAndFamily(DWRITE_TEXT_ALIGNMENT_CENTER);
			}
		}

		//HelpButton
		{
			Vec2 pos = { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.55f };
			_helpButton = CreateUI<Button>(pos, size);
			_helpButton->texture = LOADTEXTURE(L"UISprite1X1", L"Texture\\UISprite1X1.png");
			_helpButton->onlyOneCountClick = true;
			_helpButton->OnClickEvent +=
				[](int _)
				{
					GET_SINGLE(FadeManager)->LoadScene(L"HelpScene");
				};
			_helpButton->OnSelectEnterEvent +=
				[ct = _helpButton, selectedSize = selectedSize](int _)
				{
					ct->AddPos({ 0, -2 });
					ct->SetSize(selectedSize);
				};
			_helpButton->OnSelectExitEvent +=
				[ct = _helpButton, size = size](int _)
				{
					ct->AddPos({ 0, 2 });
					ct->SetSize(size);
				};

			//HelpButtonText
			{
				Text* helpButtonText = CreateUI<Text>({ 0, 0 }, size);
				helpButtonText->SetParent(_helpButton);
				helpButtonText->SetText(L"HELP");
				helpButtonText->SetWeight(DWRITE_FONT_WEIGHT_BOLD);
				helpButtonText->LoadFont(L"PFstardust", 18);
				helpButtonText->SetPitchAndFamily(DWRITE_TEXT_ALIGNMENT_CENTER);
			}
		}

		//QuitButton
		{
			Vec2 pos = { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.63f };
			_quitButton = CreateUI<Button>(pos, size);
			_quitButton->texture = LOADTEXTURE(L"UISprite1X1", L"Texture\\UISprite1X1.png");
			_quitButton->onlyOneCountClick = true;
			_quitButton->OnClickEvent +=
				[](int _)
				{
					PostQuitMessage(NULL);
				};
			_quitButton->OnSelectEnterEvent +=
				[ct = _quitButton, selectedSize = selectedSize](int _)
				{
					ct->AddPos({ 0, -2 });
					ct->SetSize(selectedSize);
				};
			_quitButton->OnSelectExitEvent +=
				[ct = _quitButton, size = size](int _)
				{
					ct->AddPos({ 0, 2 });
					ct->SetSize(size);
				};
			//QuitButtonText
			{
				Text* quitButtonText = CreateUI<Text>({ 0, 0 }, size);
				quitButtonText->SetParent(_quitButton);
				quitButtonText->SetText(L"QUIT");
				quitButtonText->SetWeight(DWRITE_FONT_WEIGHT_BOLD);
				quitButtonText->LoadFont(L"PFstardust", 18);
				quitButtonText->SetPitchAndFamily(DWRITE_TEXT_ALIGNMENT_CENTER);
			}
		}
	}
}

TitleCanvas::~TitleCanvas()
{
}
