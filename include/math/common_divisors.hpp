#pragma once
#include "common.hpp"
#include "divisors.hpp"

void CommonDivisors(ll x, ll y, VL &commonDivisors)
{
    VL divisorX;
    Divisors(x, divisorX);

    vrep(z, divisorX)
    {
        if ((y / z) * z == y) {
            commonDivisors.push_back(z);
        }
    }
}
