#include "pch.h"
#include "Stage12.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundE.h"
#include "BackgroundNull.h"
#include "BackgroundBoss.h"

Stage12::Stage12()
{
}

Stage12::~Stage12()
{
}

void Stage12::Init()
{
    AddBackground<BackgroundNull>(0, 0);
    AddBackground<BackgroundNull>(0, 1);
    AddBackground<BackgroundNull>(0, 2);
    AddBackground<BackgroundNull>(1, 1);
    AddBackground<BackgroundBoss>(1, 0);
    AddBackground<BackgroundNull>(2, 1);
    AddBackground<BackgroundNull>(2, 0);
    AddBackground<BackgroundNull>(1, 2, true);
    AddBackground<BackgroundNull>(2, 2);
}
