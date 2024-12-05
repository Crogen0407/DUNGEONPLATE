#include "pch.h"
#include "Stage1.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"

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
    AddBackground<BackgroundB>(0, 2);
    AddBackground<BackgroundB>(1, 0);
    AddBackground<BackgroundC>(1, 1);
}
