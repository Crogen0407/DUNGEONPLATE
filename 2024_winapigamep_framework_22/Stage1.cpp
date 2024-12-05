#include "pch.h"
#include "Stage1.h"
#include "BackgroundA.h"

Stage1::Stage1()
{
    
}

Stage1::~Stage1()
{
}

void Stage1::Init()
{
    AddBackground<BackgroundA>(0, 0, true);
    AddBackground<BackgroundA>(0, 1);
    AddBackground<BackgroundA>(0, 2);
    AddBackground<BackgroundA>(1, 0);
    AddBackground<BackgroundA>(1, 1);
}
