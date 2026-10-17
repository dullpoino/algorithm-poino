#pragma once
#include "common.hpp"

void getHasi(VL &order, VL &low, VL &parent_v, VL &parent_e, VL &childs, VL &hasi)
{
    ll N = sz(order);
    fill(all(hasi), 0);

    rep(i, 0, N) {
        ll p = parent_v[i];

        if (p != -1 && order[p] < low[i]) {
            hasi[parent_e[i]] = 1;
        }
    }
}
