#pragma once
#include "common.hpp"

double degToRad(double degree)
{
    return PI * degree / 180.0;
}

double radToDeg(double radian)
{
    return 180.0 * (radian / PI);
}
