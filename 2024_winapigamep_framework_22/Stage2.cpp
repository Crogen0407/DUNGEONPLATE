#include "pch.h"
#include "Stage2.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundE.h"
#include "BackgroundNull.h"


Stage2::Stage2()
{
    
}

Stage2::~Stage2()
{
}

void Stage2::Init()
{
    AddBackground<BackgroundA>(0, 1);
    AddBackground<BackgroundB>(1, 1);
    AddBackground<BackgroundNull>(1, 2);
    AddBackground<BackgroundB>(2, 1, true);
}

