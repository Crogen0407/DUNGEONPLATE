#pragma once
class PoolableObject
{
public:
	std::string name;
public:
	virtual void OnPop() abstract;
	virtual void OnPush() abstract;
};

