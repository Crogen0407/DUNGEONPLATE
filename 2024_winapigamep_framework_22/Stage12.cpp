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
    AddBackground<BackgroundD>(0, 0);
    AddBackground<BackgroundE>(0, 1);
    AddBackground<BackgroundNull>(0, 2);
    AddBackground<BackgroundC>(1, 0);
    AddBackground<BackgroundA>(1, 1);
    AddBackground<BackgroundBoss>(1, 2);
    AddBackground<BackgroundC>(2, 0);
    AddBackground<BackgroundE>(2, 1, true);
    AddBackground<BackgroundD>(2, 2);
}
