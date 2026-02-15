#pragma once
#include "common.hpp"

/**********************************************************
ランレングス圧縮
**********************************************************/

vector<pair<char, ll>> RLE(string& S)
{
    vector<pair<char, ll> > v;
    v.reserve(sz(S));

    for (auto c : S) {
        if (v.empty() || v.back().first != c) {
            v.emplace_back(c, 1);
        }
        else {
            v.back().second++;
        }
    }

    return v;
}