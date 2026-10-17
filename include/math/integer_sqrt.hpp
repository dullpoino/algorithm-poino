#pragma once
#include "common.hpp"

ll isqrt(ll x)
{
    ll sq = (ll)sqrtl((ld)x);

    while ((sq + 1) * (sq + 1) <= x) {
        ++sq;
    }
    while (sq * sq > x) {
        --sq;
    }

    return sq;
}
