#pragma once
#include "Canvas.h"
#include "SkillSlot.h"

class SkillCanvas : public Canvas
{
public:
	SkillCanvas();
	virtual ~SkillCanvas() override;

public:
	void Update() override;

public:
	void CreateSlot(Vec2 slotPos);
	void ShowSlots();
	void CloseSlot();

private:
	vector<SkillSlot*> _skillSlots;
};