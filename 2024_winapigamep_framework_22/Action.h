#pragma once
#include <list>
#include <functional>

template<typename T>
class Action
{
public:
	Action() = default;
	~Action() = default;
	
private:
	std::list<std::function<void>(T)> functions;
public:
	void operator +=(std::function<void()> fn)
	{
		functions.push_back(ft);
	}
	void operator -=(std::function<void()> fn)
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
