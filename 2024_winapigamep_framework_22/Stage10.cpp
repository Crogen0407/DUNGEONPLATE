#include "pch.h"
#include "Stage10.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundE.h"
#include "BackgroundNull.h"

Stage10::Stage10()
{
}

Stage10::~Stage10()
{
}

void Stage10::Init()
{
	AddBackground<BackgroundA>(0, 0);
	AddBackground<BackgroundA>(0, 2);
	AddBackground<BackgroundA>(1, 0, true);
	AddBackground<BackgroundA>(1, 1);
	AddBackground<BackgroundA>(1, 2);
}
