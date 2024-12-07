#include "pch.h"
#include "Stage5.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundE.h"
#include "BackgroundNull.h"


Stage5::Stage5()
{
}

Stage5::~Stage5()
{
}

void Stage5::Init()
{
	AddBackground<BackgroundA>(1, 0);
	AddBackground<BackgroundA>(0, 1);
	AddBackground<BackgroundA>(1, 1);
	AddBackground<BackgroundA>(2, 1, true);
	AddBackground<BackgroundA>(1, 2);
}