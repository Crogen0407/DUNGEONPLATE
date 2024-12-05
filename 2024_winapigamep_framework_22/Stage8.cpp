#include "pch.h"
#include "Stage8.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundE.h"
#include "BackgroundNull.h"

Stage8::Stage8()
{
}

Stage8::~Stage8()
{
}

void Stage8::Init()
{
	AddBackground<BackgroundNull>(1, 1, true);
	AddBackground<BackgroundB>(0, 0);
	AddBackground<BackgroundD>(2, 0);
	AddBackground<BackgroundD>(0, 2);
	AddBackground<BackgroundB>(2, 2);
}
