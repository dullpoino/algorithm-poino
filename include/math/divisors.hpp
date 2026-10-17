#pragma once
#include "common.hpp"

void Divisors(ll x, VL &v)
{
    repr(i, 1, x) {
        if (i * i > x) {
            break;
        }

        if (x % i == 0) {
            v.push_back(i);
            if (i * i != x) {
                v.push_back(x / i);
            }
        }
    }
}
