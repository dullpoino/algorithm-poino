#pragma once
#include "common.hpp"

/**********************************************************
Grundy数
true  : 先手の勝ち
false : 後手の勝ち
**********************************************************/

bool Grundy(VL v)
{
    ll g = 0;
    for (auto x : v) {
        g ^= x;
    }

    return (g > 0);
}