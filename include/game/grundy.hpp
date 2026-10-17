#pragma once
#include "common.hpp"

ll Grundy(VL &v)
{
    ll g = 0;

    vrep(x, v) {
        g ^= x;
    }

    return g;
}
