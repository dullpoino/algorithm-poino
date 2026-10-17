#pragma once
#include "common.hpp"

struct RangeOp
{
    bool hasSet = false;
    ll set = 0;
    ll add = 0;

    static RangeOp Add(ll x)
    {
        return { false, 0, x };
    }

    static RangeOp Set(ll x)
    {
        return { true, x, 0 };
    }
};

auto mlsum = [](ll a, ll b)
{
    return a + b;
};

auto plsum = [](ll x, RangeOp f, ll len)
{
    if (f.hasSet == true) {
        x = f.set * len;
    }
    return x + f.add * len;
};

auto clsum = [](RangeOp newer, RangeOp older)
{
    if (newer.hasSet == true) {
        return newer;
    }
    older.add += newer.add;
    return older;
};

LAZYSEGTREE seglsum(0ll, RangeOp{}, mlsum, plsum, clsum);
