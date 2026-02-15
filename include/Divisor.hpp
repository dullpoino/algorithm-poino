#pragma once
#include "common.hpp"

/**********************************************************
約数列挙
**********************************************************/

VL getDivisors(ll x)
{
    VL res;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (i * i != x) res.push_back(x / i);
        }
    }

    return res;
}

/**********************************************************
共通約数
**********************************************************/

VL getCommonDivisors(ll x, ll y)
{
    VL commonDivisors;
    auto divisorX = getDivisors(x);

    for (auto z : divisorX) {
        if ((y / z) * z == y) {
            commonDivisors.push_back(z);
        }
    }
    sort(all(commonDivisors));

    return commonDivisors;
}