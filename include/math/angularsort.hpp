#pragma once
#include "common.hpp"

// [cross]
ll muki(PLL a)
{
    if (snd(a) == 0 && fst(a) > 0 ||
        snd(a) > 0) {
        return 0;
    }

    return 1;
}

bool henkakucomp(PLL a, PLL b)
{
    ll ma = muki(a);
    ll mb = muki(b);

    if (ma != mb) {
        return ma < mb;
    }

    return cross(a, b) > 0;
}