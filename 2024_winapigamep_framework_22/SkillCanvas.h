#pragma once
#include "Canvas.h"
class Image;
class Text;
struct SkillSlot
{
	Image* base;
	Text* name;
	Text* description;
};

class SkillCanvas : public Canvas
{
public:
	SkillCanvas();
	~SkillCanvas() override;
public:
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;
public:
	vector<SkillSlot*> skillSlots;
};