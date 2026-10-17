#pragma once
#include "common.hpp"

auto msum = [](ll a, ll b)
{
    return a + b;
};

SEGTREE segsum(0ll, msum);
