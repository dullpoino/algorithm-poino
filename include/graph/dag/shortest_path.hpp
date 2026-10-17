#pragma once
#include "common.hpp"

bool minDistDAG(VVPLL &G, VL &dist, ll start)
{
    VL order;
    if (sortT(G, order) == false) {
        return false;
    }

    dist.assign(sz(G), INF);
    dist[start] = 0;

    for (auto cur : order) {
        if (dist[cur] == INF) {
            continue;
        }

        for (auto &[next, cost] : G[cur]) {
            chmin(dist[next], dist[cur] + cost);
        }
    }

    return true;
}
