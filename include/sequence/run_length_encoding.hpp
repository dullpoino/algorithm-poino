#pragma once
#include "common.hpp"

template<class T>
void RLE(const T &S, VEC<PR<typename T::value_type, ll>> &v)
{
    v.clear();

    for (const auto &x : S) {
        if (v.empty() == true || fst(v.back()) != x) {
            v.push_back({ x, 1 });
        }
        else {
            ++snd(v.back());
        }
    }
}
