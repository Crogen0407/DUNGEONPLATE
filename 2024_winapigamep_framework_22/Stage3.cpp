#include "pch.h"
#include "Stage3.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundE.h"
#include "BackgroundNull.h"


Stage3::Stage3()
{
    
}

Stage3::~Stage3()
{
}

void Stage3::Init()
{
    AddBackground<BackgroundA>(0, 0);
    AddBackground<BackgroundB>(0, 2);
    AddBackground<BackgroundNull>(1, 0);
    AddBackground<BackgroundC>(1, 1, true);
    AddBackground<BackgroundD>(1, 2);
}
