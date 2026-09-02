#pragma once

class Object;
class Pattern
{
public:
	Pattern();
	virtual ~Pattern();
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
