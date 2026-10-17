#pragma once
#include "common.hpp"

ll getDigit(ll x)
{
    if (x == 0) {
        return 1;
    }

    ll res = 0;
    while (x > 0) {
        x /= 10;
        res++;
    }

    return res;
}
