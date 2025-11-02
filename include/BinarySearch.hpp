#pragma once
#include "common.hpp"

/**********************************************************
Binary Search
**********************************************************/
ll MybinarySearch(vector<ll>& v, ll key) {
    ll left = 0;
    ll right = sz(v);

    ll res = -1, mid = 0;

    while (left < right) {
        mid = left + (right - left) / 2;

        if (v[mid] > key) {
            right = mid;
        }
        else if (v[mid] < key) {
            left = mid + 1;
        }
        else {
            res = mid;
            break;
        }
    }

    return res;
}