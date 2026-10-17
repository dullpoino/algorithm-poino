#pragma once
#include "common.hpp"

ll Comb(ll n, ll r)
{
    if (n < r || r < 0) {
        return 0;
    }

    r = min(r, n - r);

    ll res = 1;
    repr(i, 1, r) {
        res = res * (n - r + i) / i;
    }

    return res;
}
