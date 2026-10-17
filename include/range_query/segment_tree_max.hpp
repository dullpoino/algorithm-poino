#pragma once
#include "common.hpp"

auto mmax = [](ll a, ll b)
{
    return max(a, b);
};

SEGTREE segmax(-INF, mmax);
