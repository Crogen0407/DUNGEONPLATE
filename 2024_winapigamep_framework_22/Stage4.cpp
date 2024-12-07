#include "pch.h"
#include "Stage4.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundE.h"
#include "BackgroundNull.h"


Stage4::Stage4()
{
}

Stage4::~Stage4()
{
}

void Stage4::Init()
{
	AddBackground<BackgroundA>(0, 0);
	AddBackground<BackgroundB>(0, 1);
	AddBackground<BackgroundA>(0, 2, true);
	AddBackground<BackgroundC>(1, 2);
}
