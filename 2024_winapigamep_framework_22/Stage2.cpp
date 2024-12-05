#include "pch.h"
#include "Stage2.h"
#include "BackgroundA.h"

Stage2::Stage2()
{
    
}

Stage2::~Stage2()
{
}

void Stage2::Init()
{
    AddBackground<BackgroundA>(0, 0);
    AddBackground<BackgroundA>(0, 1);
    AddBackground<BackgroundA>(0, 2);
    AddBackground<BackgroundA>(1, 2);
    AddBackground<BackgroundA>(1, 1, true);
}

