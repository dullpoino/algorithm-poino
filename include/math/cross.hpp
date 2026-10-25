#pragma once
#include "common.hpp"

ll cross(const PLL &a, const PLL &b)
{
    return fst(a) * snd(b) - snd(a) * fst(b);
}
