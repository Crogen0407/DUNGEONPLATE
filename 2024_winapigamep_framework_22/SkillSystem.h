#pragma once

class Object;
class SkillSystem
{
public:
	SkillSystem();
	virtual ~SkillSystem();
public:
	virtual void Update() abstract;
	virtual void UseSkill() abstract;
	bool IsUsingSkill() { return _isUsingSkill; }
	virtual void SetOwner(Object* owner)
	{
		_owner = owner;
	}
protected:
	Object* _owner;
	bool _isUsingSkill = false;
};
