#pragma once
#include "common.hpp"

auto mmin = [](ll a, ll b)
{
    return min(a, b);
};

SEGTREE segmin(INF, mmin);
