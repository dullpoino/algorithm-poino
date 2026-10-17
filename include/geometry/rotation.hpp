#pragma once
#include "common.hpp"
#include "radian.hpp"

PR<double, double> Rotate(double x, double y, double xc, double yc, double t)
{
    double r = degToRad(t);
    return { (x - xc) * cos(r) - (y - yc) * sin(r) + xc, (x - xc) * sin(r) + (y - yc) * cos(r) + yc };
}
