#pragma once
#include "common.hpp"

double roundDouble(double x, ll N)
{
    double p = pow(10.0, N - 1);

    x *= p;
    x = round(x);
    x /= p;

    return x;
}
