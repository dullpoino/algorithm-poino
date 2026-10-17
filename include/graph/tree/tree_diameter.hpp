#pragma once
#include "common.hpp"

ll treeChokkei(VVPLL &G)
{
    PLL res;

    mostfar(G, 0, res);
    mostfar(G, fst(res), res);

    return snd(res);
}
