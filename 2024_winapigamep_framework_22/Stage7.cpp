#include "pch.h"
#include "Stage7.h"
#include "BackgroundG.h"
#include "BackgroundNull.h"

Stage8::Stage8()
{
}

Stage8::~Stage8()
{
}

void Stage8::Initialize()
{
	AddBackground<BackgroundNull>(0, 0);
	AddBackground<BackgroundNull>(2, 0);
	AddBackground<BackgroundNull>(1, 0, true);
	AddBackground<BackgroundG>(1, 1);
	AddBackground<BackgroundNull>(1, 2);
	AddBackground<BackgroundNull>(0, 2);
	AddBackground<BackgroundNull>(2, 2);
}
