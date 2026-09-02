#pragma once

float EaseOutCubic(float x)
{
	auto x2 = 1 - x;
	return 1 - (x2 * x2 * x2);
}