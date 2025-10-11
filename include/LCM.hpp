#pragma once
#include "common.hpp"

/**********************************************************
最小公倍数
オーバーフロー検知つき
**********************************************************/
ll mylcm(ll a, ll b) {
    ll x = a / gcd(a, b);
    ll y = 1000000000000000000ll / b;
    ll res = -1;
    if (x <= y) {
        res = a / gcd(a, b) * b;
    }
    return res;
}