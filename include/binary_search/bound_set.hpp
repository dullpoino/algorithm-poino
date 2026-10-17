#pragma once
#include "common.hpp"

set<ll>::iterator boundLT(set<ll> &s, ll key)
{
    auto it = s.lower_bound(key);
    if (it == s.begin()) {
        return s.end();
    }
    return prev(it);
}

set<ll>::iterator boundLE(set<ll> &s, ll key)
{
    auto it = s.upper_bound(key);
    if (it == s.begin()) {
        return s.end();
    }
    return prev(it);
}

set<ll>::iterator boundGT(set<ll> &s, ll key)
{
    return s.upper_bound(key);
}

set<ll>::iterator boundGE(set<ll> &s, ll key)
{
    return s.lower_bound(key);
}
