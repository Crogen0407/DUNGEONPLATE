#include "pch.h"
#include "Stage9.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundE.h"
#include "BackgroundNull.h"

Stage9::Stage9()
{
}

Stage9::~Stage9()
{
}

void Stage9::Init()
{
	AddBackground<BackgroundB>(0, 0);
	AddBackground<BackgroundB>(1, 0);
	AddBackground<BackgroundB>(2, 0);
	AddBackground<BackgroundB>(0, 1);
	AddBackground<BackgroundB>(1, 2, true);
	AddBackground<BackgroundB>(2, 2);

}
