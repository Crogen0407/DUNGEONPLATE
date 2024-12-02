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
		Image* fill = static_cast<Image*>(CreateUI(UIOPTION::IMAGE));
		fill->texture = LOADTEXTURE(L"OnePoint", L"Texture\\OnePoint.bmp");
		fill->SetPosAndSize(pos, size);
	}

	//BackGround
	{
		Vec2 size = { SCREEN_WIDTH/3, SCREEN_HEIGHT/3 };
		Vec2 pos = { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.55f };
		Image* background = static_cast<Image*>(CreateUI(UIOPTION::IMAGE));
		background->texture = LOADTEXTURE(L"Background", L"Texture\\Background.bmp");
		background->SetPosAndSize(pos, size);
	}

	//TitleText
	{
		Vec2 size = { SCREEN_WIDTH, SCREEN_HEIGHT };
		Vec2 pos = { size.x * 0.5f, size.y * 0.26f };
		Text* titleText = static_cast<Text*>(CreateUI(UIOPTION::TEXT));
		titleText->SetText(L"DUNGEONPLATE");
		titleText->LoadFont(L"PF스타더스트 Bold", 60, 72);
		titleText->SetPitchAndFamily(DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		titleText->SetPosAndSize(pos, size);
		titleText->SetColor(RGB(155, 188, 15));
	}

	//StartButton
	{
		Vec2 size = { 250, 32 };
		Vec2 pos = { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.47f };
		_startButton = static_cast<Button*>(CreateUI(UIOPTION::BUTTON));
		_startButton->SetPosAndSize(pos, size);
		_startButton->texture = LOADTEXTURE(L"UISprite8X1", L"Texture\\UISprite8X1.bmp");
		_startButton->OnClickEvent +=
			[](int _)
			{
				GET_SINGLE(FadeManager)->LoadScene(L"GameScene");
			};
		_startButton->OnSelectEnterEvent +=
			[ct = _startButton](int _)
			{
				ct->SetSize({ 260, 36 });
			};
		_startButton->OnSelectExitEvent +=
			[ct = _startButton](int _)
			{
				ct->SetSize({ 250, 32 });
			};
		//StartButtonText
		{
			Text* startButtonText = static_cast<Text*>(CreateUI(UIOPTION::TEXT));
			startButtonText->SetText(L"START");
			startButtonText->LoadFont(L"PF스타더스트 Bold", 18, 21);
			startButtonText->SetPitchAndFamily(DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			startButtonText->SetPosAndSize(pos, size);
			startButtonText->SetColor(RGB(15, 56, 15));
		}
	}

	//HelpButton
	{
		Vec2 size = { 250, 32 };
		Vec2 pos = { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.55f };
		_helpButton = static_cast<Button*>(CreateUI(UIOPTION::BUTTON));
		_helpButton->SetPosAndSize(pos, size);
		_helpButton->texture = LOADTEXTURE(L"UISprite8X1", L"Texture\\UISprite8X1.bmp");
		_helpButton->OnClickEvent +=
			[](int _)
			{
				GET_SINGLE(FadeManager)->LoadScene(L"HelpScene");
			};
		_helpButton->OnSelectEnterEvent +=
			[ct = _helpButton](int _)
			{
				ct->SetSize({ 260, 36 });
			};
		_helpButton->OnSelectExitEvent +=
			[ct = _helpButton](int _)
			{
				ct->SetSize({ 250, 32 });
			};

		//HelpButtonText
		{
			Text* helpButtonText = static_cast<Text*>(CreateUI(UIOPTION::TEXT));
			helpButtonText->SetText(L"HELP");
			helpButtonText->LoadFont(L"PF스타더스트 Bold", 18, 21);
			helpButtonText->SetPitchAndFamily(DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			helpButtonText->SetPosAndSize(pos, size);
			helpButtonText->SetColor(RGB(15, 56, 15));
		}
	}

	//QuitButton
	{
		Vec2 size = { 250, 32 };
		Vec2 pos = { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.63f };
		_quitButton = static_cast<Button*>(CreateUI(UIOPTION::BUTTON));
		_quitButton->SetPosAndSize(pos, size);
		_quitButton->texture = LOADTEXTURE(L"UISprite8X1", L"Texture\\UISprite8X1.bmp");
		_quitButton->OnClickEvent +=
			[](int _)
			{
				PostQuitMessage(NULL);
			};
		_quitButton->OnSelectEnterEvent +=
			[ct = _quitButton](int _)
			{
				ct->SetSize({ 260, 36 });
			};
		_quitButton->OnSelectExitEvent +=
			[ct = _quitButton](int _)
			{
				ct->SetSize({ 250, 32 });
			};
		//QuitButtonText
		{
			Text* quitButtonText = static_cast<Text*>(CreateUI(UIOPTION::TEXT));
			quitButtonText->SetText(L"QUIT");
			quitButtonText->LoadFont(L"PF스타더스트 Bold", 18, 21);
			quitButtonText->SetPitchAndFamily(DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			quitButtonText->SetPosAndSize(pos, size);
			quitButtonText->SetColor(RGB(15, 56, 15));
		}
	}

	//DevText
	{
		Vec2 size = { SCREEN_WIDTH, SCREEN_HEIGHT };
		Vec2 pos = { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f };

		Text* devText = static_cast<Text*>(CreateUI(UIOPTION::TEXT));
		devText->SetText(L"김진후, 정윤찬, 최영환");
		devText->LoadFont(L"PF스타더스트 Bold", 18, 21);
		devText->SetPitchAndFamily(DT_BOTTOM | DT_RIGHT | DT_SINGLELINE);
		devText->SetPosAndSize(pos, size);
		devText->SetColor(RGB(155, 188, 15));
	}
}

TitleCanvas::~TitleCanvas()
{
}

void TitleCanvas::Update()
{
	Canvas::Update();
}

void TitleCanvas::LateUpdate()
{
	Canvas::LateUpdate();
}

void TitleCanvas::Render(HDC hdc)
{
	Canvas::Render(hdc);
}
