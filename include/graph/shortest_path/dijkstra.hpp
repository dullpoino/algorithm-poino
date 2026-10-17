#pragma once
#include "common.hpp"

void Dijkstra(VVPLL &G, VL &dist, ll start)
{
    VEC<bool> kakutei(sz(G), false);
    pqasc<PLL> q;

    dist[start] = 0;
    q.push({ dist[start], start });

    while (q.empty() == false) {
        auto [curv, curp] = poppq(q);

        if (kakutei[curp] == false) {
            kakutei[curp] = true;

            for (auto [next, cost] : G[curp]) {
                if (chmin(dist[next], curv + cost) == true) {
                    q.push({ dist[next], next });
                }
            }
        }
    }
}
