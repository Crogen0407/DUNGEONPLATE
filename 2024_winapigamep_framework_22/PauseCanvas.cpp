#include "pch.h"
#include "PauseCanvas.h"
#include "Text.h"

PauseCanvas::PauseCanvas()
{
	SetName(L"PauseCanvas");

	//TitleText
	{
		Vec2 size = {1000, 100};
		Vec2 pos = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 -20 };
		Text* text = CreateUI<Text>(pos, size);
		text->SetText(L"�Ͻ� ����");
		text->LoadFont(L"PF��Ÿ����Ʈ Bold", 60, 72);
	}

	//DescriptionText
	{
		Vec2 size = { 1000, 100 };
		Vec2 pos = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 +20};
		Text* text = CreateUI<Text>(pos, size);
		text->SetText(L"Esc�� ���� �ٽ� ����...");
		text->LoadFont(L"PF��Ÿ����Ʈ Bold", 50, 63);
	}
}

PauseCanvas::~PauseCanvas()
{
}
