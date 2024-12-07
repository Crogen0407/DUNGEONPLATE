#include "pch.h"
#include "GameClearCanvas.h"
#include "Button.h"
#include "Text.h"
#include "Slider.h"
#include "Image.h"
#include "ResourceManager.h"
#include "TimeManager.h"
#include "FadeManager.h"
#include "GameManager.h"
#include <format>

GameClearCanvas::GameClearCanvas()
{
	SetName(L"GameClearCanvas");

	//Background
	{
		Vec2 size = { SCREEN_WIDTH, SCREEN_HEIGHT };
		Vec2 pos = { size.x * 0.5f, size.y * 0.5f };
		Image* background = CreateUI<Image>(pos, size);
		background->texture = LOADTEXTURE(L"GameClear", L"Texture\\GameClear.bmp");
	}

	//TitleText
	{
		Vec2 size = { SCREEN_WIDTH, SCREEN_HEIGHT };
		Vec2 pos = { size.x * 0.5f, size.y * 0.3f };
		titleText = CreateUI<Text>(pos, size);
		titleText->SetText(L"CLEAR!");
		titleText->LoadFont(L"PF스타더스트 Bold", 60, 72);
		titleText->SetPitchAndFamily(DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		titleText->SetColor(RGB(155, 188, 15));
	}

	//MentText
	{
		Vec2 size = { SCREEN_WIDTH, SCREEN_HEIGHT };
		Vec2 pos = { size.x * 0.5f, size.y * 0.4f };
		mentText = CreateUI<Text>(pos, size);
		mentText->SetText(L"축하드립니다!");
		mentText->LoadFont(L"PF스타더스트", 20, 25);
		mentText->SetPitchAndFamily(DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		mentText->SetColor(RGB(155, 188, 15));
	}

	//GotoTitleSceneButton
	{
		Vec2 size = { 400, 50 };
		Vec2 pos = { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.585f };
		gotoTitleSceneButton = CreateUI<Button>(pos, size);
		gotoTitleSceneButton->texture = LOADTEXTURE(L"UISprite8X1", L"Texture\\UISprite8X1.bmp");
		gotoTitleSceneButton->onlyOneCountClick = true;
		gotoTitleSceneButton->OnClickEvent +=
			[](int _)
			{
				GET_SINGLE(FadeManager)->LoadScene(L"TitleScene");
			};
		//GotoTitleButtonText
		{
			Text* retryButtonText = CreateUI<Text>(pos, size);
			retryButtonText->SetText(L"GOTOTITLE");
			retryButtonText->LoadFont(L"PF스타더스트 Bold", 18, 21);
			retryButtonText->SetPitchAndFamily(DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			retryButtonText->SetColor(RGB(15, 56, 15));
		}
	}

	//InfoText
	{
		Vec2 size = { 300, 100 };
		Vec2 pos = { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.506f };

		Text* infoText = CreateUI<Text>(pos, size);
		wstring str;
		//스테이지 정보 가지고 오기
		str += L"TIME";
		infoText->SetText(str);
		infoText->LoadFont(L"PF스타더스트 Bold", 17, 19);
		infoText->SetPitchAndFamily(DT_LEFT | DT_VCENTER);
		infoText->SetColor(RGB(15, 56, 15));
	}

	//InfoValueText
	{
		Vec2 size = { 300, 100 };
		Vec2 pos = { SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.506f };

		Text* infoValueText = CreateUI<Text>(pos, size);
		wstring str;

		//스테이지 정보 가지고 오기
		str += std::format(L"{0:02} : {1:02}", (int)TIME/60, (int)TIME%60);
		infoValueText->SetText(str);
		infoValueText->LoadFont(L"PF스타더스트 Bold", 17, 19);
		infoValueText->SetPitchAndFamily(DT_RIGHT | DT_VCENTER);
		infoValueText->SetColor(RGB(15, 56, 15));
	}
}

GameClearCanvas::~GameClearCanvas()
{
}
