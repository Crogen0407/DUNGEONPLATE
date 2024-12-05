#include "pch.h"
#include "Stage1.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundE.h"
#include "BackgroundNull.h"

Stage1::Stage1()
{
}

Stage1::~Stage1()
{
}

void Stage1::Init()
{
    //AddBackground<BackgroundB>(1, 1);
    //AddBackground<BackgroundA>(1, 2, true);

    //AddBackground<BackgroundA>(0, 1);
    //AddBackground<BackgroundC>(1, 1);
    //AddBackground<BackgroundB>(1, 2, true);
    //AddBackground<BackgroundB>(2, 1);

    /*AddBackground<BackgroundA>(0, 0);
    AddBackground<BackgroundB>(0, 2);
    AddBackground<BackgroundNull>(1, 0);
    AddBackground<BackgroundC>(1, 1, true);
    AddBackground<BackgroundD>(1, 2);*/



   /*AddBackground<BackgroundA>(1, 0);
    AddBackground<BackgroundB>(0, 1);
    AddBackground<BackgroundB>(1, 1, true);
    AddBackground<BackgroundB>(2, 1);
    AddBackground<BackgroundE>(1, 2);*/
}
