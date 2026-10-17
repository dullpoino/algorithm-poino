#pragma once
#include "common.hpp"

void getKansetu(VL &order, VL &low, VL &parent_v, VL &parent_e, VL &childs, VL &kansetu)
{
    ll N = sz(order);
    kansetu.assign(N, 0);

    rep(i, 0, N) {
        ll p = parent_v[i];

        if (p == -1) {
            if (childs[i] >= 2) {
                kansetu[i] = 1;
            }
        }
        else if (parent_v[p] != -1 && order[p] <= low[i]) {
            kansetu[p] = 1;
        }
    }
}
