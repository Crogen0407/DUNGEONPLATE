#include "pch.h"
#include "Stage9.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundE.h"
#include "BackgroundF.h"
#include "BackgroundNull.h"

Stage9::Stage9()
{
}

Stage9::~Stage9()
{
}

void Stage9::Initialize()
{
	AddBackground<BackgroundF>(0, 0);
	AddBackground<BackgroundA>(1, 0);
	AddBackground<BackgroundF>(2, 0);
	AddBackground<BackgroundNull>(0, 1);
	AddBackground<BackgroundB>(1, 2, true);
	AddBackground<BackgroundNull>(2, 2);
	AddBackground<BackgroundB>(0, 2);

}
