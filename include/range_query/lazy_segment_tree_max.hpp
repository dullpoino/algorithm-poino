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

auto mlmax = [](ll a, ll b)
{
    return max(a, b);
};

auto plmax = [](ll x, RangeOp f, ll len)
{
    if (f.hasSet == true) {
        x = f.set;
    }
    return x + f.add;
};

auto clmax = [](RangeOp newer, RangeOp older)
{
    if (newer.hasSet == true) {
        return newer;
    }
    older.add += newer.add;
    return older;
};

LAZYSEGTREE seglmax(-INF, RangeOp{}, mlmax, plmax, clmax);
