#pragma once
#include "Stage.h"
class Stage1 : public Stage
{
public:
	Stage1();
	~Stage1() override;
public:
	void Init() override;
	void Update() override;
	void Release() override;
};

