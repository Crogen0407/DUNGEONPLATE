#include "pch.h"
#include "HelpCanvas.h"
#include "Image.h"
#include "Text.h"
#include "Button.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "FadeManager.h"
#include <format>

HelpCanvas::HelpCanvas()
{
	_slides.push_back(new Slide(L"<W>, <A>, <S>, <D>로 움직일 수 있습니다."));
	_slides.push_back(new Slide(L"플레이어는 마우스 방향을 바라봅니다.\n클릭을 하면 공격할 수 있고요."));
	_slides.push_back(new Slide(L"평범한 공격으론 던전의 적에게 흔집조차 낼 수 없습니다."));
	_slides.push_back(new Slide(L"적들의 투사체를 튕겨내세요!\n그것이 공격할 수 있는 유일한 방법입니다."));
	_slides.push_back(new Slide(L"적을 처치하면 경험치를 획득합니다."));
	_slides.push_back(new Slide(L"레벨업하여 다양한 스킬들을 획득해보세요."));
	//slides.push_back(new Slide(L"그럼 던전에서 뵙겠습니다. 행운을 빌어요."));

	for (int i = 0; i < _slides.size(); i++)
	{
		std::wstring flieName = std::format(L"Slide{0:02}", (i + 1));
		_slides[i]->texture = LOADTEXTURE(flieName, L"Texture\\"+ flieName+ L".png");
	}

	//Slide
	{
		Vec2 size = { SCREEN_WIDTH, SCREEN_HEIGHT };
		Vec2 pos = { size.x / 2, size.y / 2 };
		_slideImage = CreateUI<Image>(pos, size);
		_slideImage->useNineSlice = false;
		_slideImage->texture = _slides[0]->texture;
	}

	//DescriptionText
	{
		Vec2 size = { SCREEN_WIDTH , (SCREEN_HEIGHT / 8) * 2 };
		Vec2 pos = { SCREEN_WIDTH/2.f, SCREEN_HEIGHT-(size.y/2)};
		_descriptionText = CreateUI<Text>(pos, size);
		_descriptionText->SetColor(0x8bac0f);
		_descriptionText->SetWeight(DWRITE_FONT_WEIGHT_BOLD);
		_descriptionText->LoadFont(L"PFstardust", 28);
		_descriptionText->SetPitchAndFamily(DWRITE_TEXT_ALIGNMENT_CENTER);
		_descriptionText->SetText(_slides[0]->description);
	}
}

HelpCanvas::~HelpCanvas()
{
	for (int i = 0; i < _slides.size(); i++)
	{
		delete _slides[i];
	}
}

void HelpCanvas::Update()
{
	if (GET_KEYDOWN(KEY_TYPE::LBUTTON))
	{
		++_curSlide;
		if (_curSlide > _slides.size()-1 && _isFading == false)
		{
			_isFading = true;
			GET_SINGLE(FadeManager)->LoadScene(L"TitleScene");
			return;
		}
		if (_isFading == true) return;
		_slideImage->texture = _slides[_curSlide]->texture;
		_descriptionText->SetText(_slides[_curSlide]->description);
	}
}