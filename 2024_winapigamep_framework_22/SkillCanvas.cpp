#include "pch.h"
#include "SkillCanvas.h"
#include "Button.h"
#include "Text.h"
#include "ResourceManager.h"
#include "SkillManager.h"
#include "TimeManager.h"
#include "XPManager.h"
#include "InputManager.h"
#include "Skill.h"

SkillCanvas::SkillCanvas()
{
	SetName(L"SkillCanvas");
	GET_SINGLE(XPManager)->LevelUpEvent.Clear();
	_skillSlots.clear();

	GET_SINGLE(ResourceManager)->LoadSound(L"LevelUp", L"Sound\\LevelUp.wav", SOUND_CHANNEL::EFFECT3);

	Vec2 center = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	int xDeltaPos = 300;

	{
		Vec2 size = { SCREEN_WIDTH * 2, 420 };
		Vec2 pos = center;
		Image* backImage = CreateUI<Image>(pos, size);
		backImage->texture = LOADTEXTURE(L"UISprite1X1", L"Texture\\UISprite1X1.png");
	}

	CreateSlot(center - Vec2(xDeltaPos, 0));
	CreateSlot(center);
	CreateSlot(center + Vec2(xDeltaPos, 0));

	GET_SINGLE(XPManager)->LevelUpEvent +=
		[ct = this](int level)
		{
			ct->ShowSlots();
		};

	CloseSlot();
}

SkillCanvas::~SkillCanvas()
{
	_skillSlots.clear();
}

void SkillCanvas::CreateSlot(Vec2 slotPos)
{
	SkillSlot* skillSlot = CreateUI<SkillSlot>(slotPos, Vec2(250, 320));

	Vec2 namePos = Vec2(0, -110);
	Vec2 nameSize = Vec2(skillSlot->GetSize().x - 30, 30.f);

	Vec2 levelPos = Vec2(0, -64);
	Vec2 levelSize = Vec2(skillSlot->GetSize().x - 30, 30.f);

	Vec2 descriptionPos = Vec2(0, 110);
	Vec2 descriptionSize = skillSlot->GetSize() - Vec2(30, 30);

	skillSlot->name			= CreateUI<Text>(namePos, nameSize);
	skillSlot->level		= CreateUI<Text>(levelPos, levelSize);
	skillSlot->description	= CreateUI<Text>(descriptionPos, descriptionSize);

	skillSlot->level->SetText(L"New!");
	skillSlot->texture = LOADTEXTURE(L"UISprite1X1", L"Texture\\UISprite1X1.png");

	skillSlot->name->SetWeight(DWRITE_FONT_WEIGHT_BOLD);
	skillSlot->name->LoadFont(L"PFstardust", 25);
	skillSlot->name->SetPitchAndFamily();
	skillSlot->name->SetParent(skillSlot);

	skillSlot->level->LoadFont(L"PFstardust", 18);
	skillSlot->level->SetPitchAndFamily();
	skillSlot->level->SetParent(skillSlot);

	skillSlot->description->LoadFont(L"PFstardust", 15);
	skillSlot->description->SetPitchAndFamily(DWRITE_TEXT_ALIGNMENT_LEADING, DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
	skillSlot->description->SetParent(skillSlot);

	//Button Events
	skillSlot->OnClickEvent +=
		[ct = this, skillSlot, player = GET_SINGLE(SkillManager)->player](int _)
		{
			skillSlot->skill->OnLevelUp(player);
			ct->CloseSlot();
		};

	skillSlot->OnSelectEnterEvent +=
		[skillSlot](int _)
		{
			Vec2 posDelta = { 0, -10 };
			skillSlot->SetSize({250 * 1.05f, 320 * 1.05f });
			skillSlot->AddPosition(posDelta);
		};

	skillSlot->OnSelectExitEvent +=
		[skillSlot](int _)
		{
			Vec2 posDelta = { 0, 10 };
			skillSlot->SetSize({ 250, 320 });
			skillSlot->AddPosition(posDelta);
		};


	_skillSlots.push_back(skillSlot);
}

void SkillCanvas::ShowSlots()
{
	GET_SINGLE(ResourceManager)->Play(L"LevelUp");

	vector<Skill*> selectedSkills = GET_SINGLE(SkillManager)->GetRandomSkills();
	enable = true;

	assert(selectedSkills.size() == _skillSlots.size());

	int i = 0;
	for (auto skillSlot : _skillSlots)
	{
		skillSlot->Init(selectedSkills[i]);
		i++;
	}

	TIMESCALE = 0;
}

void SkillCanvas::CloseSlot()
{
	TIMESCALE = 1;

	enable = false;
}
