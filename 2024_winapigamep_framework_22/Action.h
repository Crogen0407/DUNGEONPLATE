#pragma once
#include <list>

template<typename T>
class Action
{
public:
	Action() = default;
	~Action() = default;
private:
	std::list<void(*)(T)> functions;
public:
	void operator +=(void(*ft)(T))
	{
		functions.push_back(ft);
	}
	void operator -=(void(*ft)(T))
	{
		functions.remove(ft);
	}
public:
	void Clear()
	{
		functions.clear();
	}
public:
	void Invoke(T value)
	{
		for (auto ft : functions)
		{
			ft(value);
		}
	}
};
