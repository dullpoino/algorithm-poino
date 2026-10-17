#pragma once
#include "common.hpp"

template<class F>
ll BinarySearchLeft(ll left, ll right, F f)
{
    ll ng = left - 1;
    ll ok = right;

    while (ok - ng > 1) {
        ll mid = midpoint(ng, ok);

        if (f(mid) == true) {
            ok = mid;
        }
        else {
            ng = mid;
        }
    }

    return ok;
}
