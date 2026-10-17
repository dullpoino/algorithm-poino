#pragma once
#include "common.hpp"

VL::iterator boundLT(VL &v, ll key)
{
    auto it = lower_bound(all(v), key);
    if (it == v.begin()) {
        return v.end();
    }
    return prev(it);
}

VL::iterator boundLE(VL &v, ll key)
{
    auto it = upper_bound(all(v), key);
    if (it == v.begin()) {
        return v.end();
    }
    return prev(it);
}

VL::iterator boundGT(VL &v, ll key)
{
    return upper_bound(all(v), key);
}

VL::iterator boundGE(VL &v, ll key)
{
    return lower_bound(all(v), key);
}

ll countLT(const VL &v, ll key)
{
    return lower_bound(all(v), key) - v.begin();
}

ll countLE(const VL &v, ll key)
{
    return upper_bound(all(v), key) - v.begin();
}

ll countGT(const VL &v, ll key)
{
    return v.end() - upper_bound(all(v), key);
}

ll countGE(const VL &v, ll key)
{
    return v.end() - lower_bound(all(v), key);
}
