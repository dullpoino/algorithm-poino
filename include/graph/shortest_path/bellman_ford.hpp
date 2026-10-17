#pragma once
#include "common.hpp"

bool BellmanFord(ll N, VEC<tuple<ll, ll, ll>> &E, VL &dist, ll start)
{
    dist[start] = 0;

    rep(i, 0, N) {
        bool update = false;

        for (auto [from, to, cost] : E) {
            if (dist[from] == INF) {
                continue;
            }

            if (chmin(dist[to], dist[from] + cost) == true) {
                update = true;

                if (i == N - 1) {
                    return false;
                }
            }
        }

        if (update == false) {
            break;
        }
    }

    return true;
}
