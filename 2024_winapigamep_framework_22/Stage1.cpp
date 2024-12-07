#include "pch.h"
#include "Stage1.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundE.h"
#include "BackgroundBoss.h"
#include "BackgroundNull.h"

Stage1::Stage1()
{
}

Stage1::~Stage1()
{
}

void Stage1::Init()
{
    AddBackground<BackgroundB>(1, 1);
    AddBackground<BackgroundA>(1, 2, true);
}