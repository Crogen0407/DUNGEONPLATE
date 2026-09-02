#include "pch.h"
#include "Stage11.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundE.h"
#include "BackgroundG.h"
#include "BackgroundNull.h"

Stage11::Stage11()
{
}

Stage11::~Stage11()
{
}

void Stage11::Initialize()
{
	AddBackground<BackgroundNull>(0, 0);
	AddBackground<BackgroundE>(0, 1);
	AddBackground<BackgroundNull>(0, 2);
	AddBackground<BackgroundG>(1, 0);
	AddBackground<BackgroundNull>(1, 2, true);
	AddBackground<BackgroundNull>(2, 0);
	AddBackground<BackgroundE>(2, 1);
	AddBackground<BackgroundNull>(2, 2);
}
