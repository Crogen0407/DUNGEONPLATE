#include "pch.h"
#include "SkillCanvas.h"
#include "Image.h"
#include "Text.h"
#include "ResourceManager.h"

SkillCanvas::SkillCanvas()
{
	for (int i = 0; i < 3; i++)
	{
		SkillSlot* skillSlot = new SkillSlot;
		skillSlot->base->texture = LOADTEXTURE(L"Base", L"Texture\\Base");
		//skillSlot->name->LoadFont();
		//skillSlot->description->LoadFont();
		skillSlots.push_back(skillSlot);
	}
}

SkillCanvas::~SkillCanvas()
{
}

void SkillCanvas::Update()
{
}

void SkillCanvas::LateUpdate()
{
}

void SkillCanvas::Render(HDC hdc)
{
}
