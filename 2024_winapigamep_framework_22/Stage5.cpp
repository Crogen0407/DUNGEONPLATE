#include "pch.h"
#include "Stage5.h"
#include "BackgroundA.h"
#include "BackgroundB.h"
#include "BackgroundC.h"
#include "BackgroundD.h"
#include "BackgroundE.h"

Stage5::Stage5()
{
}

Stage5::~Stage5()
{
}

void Stage5::Init()
{
	AddBackground<BackgroundA>(0, 0);
}