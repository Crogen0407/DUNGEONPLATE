#include "pch.h"
#include "Stage6.h"
#include "BackgroundNull.h"
#include "BackgroundE.h"

Stage6::Stage6()
{
}

Stage6::~Stage6()
{
}

void Stage6::Init()
{
	AddBackground<BackgroundNull>(0, 0);
	AddBackground<BackgroundNull>(0, 1);
	AddBackground<BackgroundNull>(0, 2);
	AddBackground<BackgroundNull>(1, 0);
	AddBackground<BackgroundE>(1, 1, true);
	AddBackground<BackgroundNull>(1, 2);
	AddBackground<BackgroundNull>(2, 0);
	AddBackground<BackgroundNull>(2, 1);
	AddBackground<BackgroundNull>(2, 2);
}
