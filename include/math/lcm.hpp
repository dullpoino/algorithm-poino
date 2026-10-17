#pragma once
#include "common.hpp"

ll lcmB(ll a, ll b)
{
    ll g = gcd(a, b);
    ll x = a / g;
    ll y = 1000000000000000000ll / b;
    ll res = -1;
    if (x <= y) {
        res = x * b;
    }
    return res;
}
