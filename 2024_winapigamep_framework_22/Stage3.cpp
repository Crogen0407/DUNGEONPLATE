#include "pch.h"
#include "Stage3.h"
#include "BackgroundA.h"

Stage3::Stage3()
{
    
}

Stage3::~Stage3()
{
}

void Stage3::Init()
{
    AddBackground<BackgroundA>(0, 0);
    AddBackground<BackgroundA>(0, 1);
    AddBackground<BackgroundA>(0, 2);
    AddBackground<BackgroundA>(1, 0);
    AddBackground<BackgroundA>(1, 1, true);
}
