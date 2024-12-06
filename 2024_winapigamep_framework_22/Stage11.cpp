#include "pch.h"
#include "Stage11.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundE.h"
#include "BackgroundNull.h"

Stage11::Stage11()
{
}

Stage11::~Stage11()
{
}

void Stage11::Init()
{
	AddBackground<BackgroundC>(0, 0);
	AddBackground<BackgroundC>(0, 1);
	AddBackground<BackgroundNull>(0, 2);
	AddBackground<BackgroundD>(1, 0);
	AddBackground<BackgroundNull>(1, 2);
	AddBackground<BackgroundD>(2, 0);
	AddBackground<BackgroundA>(2, 1, true);
	AddBackground<BackgroundE>(2, 2);
}
