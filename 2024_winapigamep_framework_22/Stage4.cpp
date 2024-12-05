#include "pch.h"
#include "Stage4.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundE.h"

Stage4::Stage4()
{
}

Stage4::~Stage4()
{
}

void Stage4::Init()
{
	AddBackground<BackgroundA>(0, 0);
}
