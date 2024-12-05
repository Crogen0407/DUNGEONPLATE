#include "pch.h"
#include "Stage7.h"
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

void Stage7::Init()
{
	AddBackground<BackgroundA>(1, 0);
	AddBackground<BackgroundA>(1, 1);
	AddBackground<BackgroundC>(1, 2, true);
	AddBackground<BackgroundB>(0, 2);
	AddBackground<BackgroundB>(2, 2);
}
