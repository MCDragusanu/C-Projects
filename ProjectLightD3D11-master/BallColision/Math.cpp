#include "Math.h"
#include <iostream>
#include <d2d1.h>

float Math::CalculateLenght(D2D1_POINT_2F Point1, D2D1_POINT_2F Point2)
{
	return sqrt((Point2.x - Point1.x) * (Point2.x - Point1.x) + (Point2.y - Point1.y) * (Point2.y - Point1.y));
}