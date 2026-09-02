#include "pch.h"
#include "Stage10.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundG.h"
#include "BackgroundNull.h"

Stage10::Stage10()
{
}

Stage10::~Stage10()
{
}

void Stage10::Initialize()
{
	AddBackground<BackgroundG>(0, 0);
	AddBackground<BackgroundD>(0, 2);
	AddBackground<BackgroundNull>(1, 0, true);
	AddBackground<BackgroundD>(1, 1);
	AddBackground<BackgroundNull>(1, 2);
}
