#pragma once
#include "Button.h"
class Skill;
class Text;
class SkillSlot :
    public Button
{
public:
    SkillSlot();
    ~SkillSlot() override;
public:
    void Init(Skill* skill);
public:
    Text* name;
    Text* level;
    Text* description;
    Skill* skill;
};

