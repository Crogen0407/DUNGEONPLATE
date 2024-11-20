#pragma once
#include <list>
class Tween;
class Sequence
{
private:
	std::list<Tween> tweens;
public:
	//Append
	Sequence* Append(Tween& tween)
	{
		tweens.push_back(tween);
		return this;
	}

	//Join
	Sequence* Join(Tween& tween)
	{
		tweens.push_back(tween);
		return this;
	}
};