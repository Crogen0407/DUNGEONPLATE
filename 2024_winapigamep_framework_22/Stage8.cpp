#include "pch.h"
#include "Stage8.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundE.h"
#include "BackgroundNull.h"

Stage7::Stage7()
{
}

Stage7::~Stage7()
{
}

void Stage7::Initialize()
{
	AddBackground<BackgroundNull>(1, 1, true);
	AddBackground<BackgroundB>(0, 1);
	AddBackground<BackgroundD>(1, 0);
	AddBackground<BackgroundD>(1, 2);
	AddBackground<BackgroundB>(2, 1);
}
