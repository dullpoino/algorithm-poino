#pragma once
#include "common.hpp"

/**********************************************************
Binary Search
**********************************************************/

ll BinarySearch_Leftmost(VL& v, ll key)
{
    ll left = 0;
    ll right = sz(v);

    while (left < right) {
        ll mid = left + (right - left) / 2;

        if (v[mid] >= key) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    if (left < sz(v) && v[left] == key) {
        return left;
    }

    return -1;
}

ll BinarySearch_Rightmost(VL& v, ll key)
{
    ll left = 0;
    ll right = sz(v);

    while (left < right) {
        ll mid = left + (right - left) / 2;

        if (v[mid] > key) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    ll l = left - 1;
    if (0 <= l && l < sz(v) && v[l] == key) {
        return l;
    }

    return -1;
}