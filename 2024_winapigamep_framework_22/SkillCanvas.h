#pragma once
#include "Canvas.h"
#include "SkillSlot.h"

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
	void CreateSlot(Vec2 slotPos);
	void ShowSlots();
	void CloseSlot();
private:
	vector<SkillSlot*> _skillSlots;
private:
	bool showSkillSlots = false;
};