#include "pch.h"
#include "SkillCanvas.h"
#include "Button.h"
#include "Text.h"
#include "ResourceManager.h"
#include "SkillManager.h"
#include "TimeManager.h"
#include "XPManager.h"

SkillCanvas::SkillCanvas()
{
	SetName(L"SkillCanvas");
	int slotCount = 3;
	Vec2 center = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	int xDeltaPos = 175;
	CreateSlot(center - Vec2(xDeltaPos, 0));
	CreateSlot(center);
	CreateSlot(center + Vec2(xDeltaPos, 0));

	GET_SINGLE(XPManager)->LevelUpEvent +=
		[ct = this](int level)
		{
			ct->ShowSlots();
		};
}

SkillCanvas::~SkillCanvas()
{
}

void SkillCanvas::Update()
{
	Canvas::Update();
	//약간 둥둥 거리는 거 만들기
}

void SkillCanvas::LateUpdate()
{
	if (showSkillSlots == false) return;
	Canvas::LateUpdate();
}

void SkillCanvas::Render(HDC hdc)
{
	if (showSkillSlots == false) return;
	Canvas::Render(hdc);
}

void SkillCanvas::CreateSlot(Vec2 slotPos)
{
	SkillSlot* skillSlot = new SkillSlot;

	skillSlot->pos = slotPos;
	skillSlot->size = Vec2(150, 200);

	skillSlot->base = static_cast<Button*>(CreateUI(UIOPTION::BUTTON));
	skillSlot->name = static_cast<Text*>(CreateUI(UIOPTION::TEXT));
	skillSlot->level = static_cast<Text*>(CreateUI(UIOPTION::TEXT));
	skillSlot->description = static_cast<Text*>(CreateUI(UIOPTION::TEXT));
	skillSlot->level->SetText(L"New!");
	skillSlot->base->texture = LOADTEXTURE(L"UISpriteSlot", L"Texture\\UISpriteSlot.bmp");

	skillSlot->name->LoadFont(L"PF스타더스트 Bold", 15, 18);
	skillSlot->name->SetPitchAndFamily(DT_VCENTER);

	skillSlot->level->LoadFont(L"PF스타더스트", 9, 12);
	skillSlot->level->SetPitchAndFamily(DT_VCENTER);

	skillSlot->description->LoadFont(L"PF스타더스트", 12, 15);
	skillSlot->description->SetPitchAndFamily(DT_LEFT | DT_TOP);

	Vec2 namePos = Vec2(0, -55) + skillSlot->pos;
	Vec2 nameSize = Vec2(skillSlot->size.x - 30, 30.f);

	Vec2 levelPos = Vec2(0, -32) + skillSlot->pos;
	Vec2 levelSize = Vec2(skillSlot->size.x-30, 30.f);

	Vec2 descriptionPos = Vec2(0, 55) + skillSlot->pos;
	Vec2 descriptionSize = skillSlot->size - Vec2(30, 30);

	skillSlot->base->SetPos(skillSlot->pos);
	skillSlot->base->SetSize(skillSlot->size);

	skillSlot->name->SetPos(namePos);
	skillSlot->name->SetSize(nameSize);

	skillSlot->level->SetPos(levelPos);
	skillSlot->level->SetSize(levelSize);

	skillSlot->description->SetPos(descriptionPos);
	skillSlot->description->SetSize(descriptionSize);

	skillSlot->base->OnClickEvent +=
		[ct = this, ss = skillSlot, player = GET_SINGLE(SkillManager)->player](int _)
		{
			ss->skill->OnLevelUp(player);
			ct->CloseSlot();
		};

	skillSlots.push_back(skillSlot);
}

void SkillCanvas::ShowSlots()
{
	vector<Skill*> selectedSkills = GET_SINGLE(SkillManager)->GetRendomSkills();
	showSkillSlots = true;
	int i = 0;
	for (auto skillSlot : skillSlots)
	{
		skillSlot->Init(selectedSkills[i]);
		i++;
	}

	TIMESCALE = 0;
}

void SkillCanvas::CloseSlot()
{
	TIMESCALE = 1;

	showSkillSlots = false;
}
