#pragma once
#include <list>
#include <functional>

template<typename T>
class Action
{
	using Func = std::function<void(T)>;
public:
	Action() = default;
	~Action()
	{
	}
	
private:
	std::list<Func> functions;
public:
	void operator +=(Func fn)
	{
		functions.push_back(fn);
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
