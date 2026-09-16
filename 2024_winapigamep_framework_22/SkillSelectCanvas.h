#pragma once
#include "Canvas.h"
#include "SkillSlot.h"

class SkillSelectCanvas : public Canvas
{
public:
	SkillSelectCanvas();
	virtual ~SkillSelectCanvas() override;

public:
	void CreateSlot(Vec2 slotPos);
	void ShowSlots();
	void CloseSlot();

private:
	vector<SkillSlot*> _skillSlots;
};