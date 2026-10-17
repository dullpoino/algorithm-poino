#pragma once
#include "common.hpp"

template<class F>
ll BinarySearchRight(ll left, ll right, F f)
{
    ll ok = left - 1;
    ll ng = right;

    while (ng - ok > 1) {
        ll mid = midpoint(ok, ng);

        if (f(mid) == true) {
            ok = mid;
        }
        else {
            ng = mid;
        }
    }

    return ok;
}
