#pragma once
#include "common.hpp"

void bfs(VVL &G, VL &start, VL &dist)
{
    ll N = sz(G);
    dist.assign(N, INF);

    deque<ll> q;
    for (auto v : start) {
        if (dist[v] != INF) {
            continue;
        }

        q.push_back(v);
        dist[v] = 0;
    }

    while (q.empty() == false) {
        auto cur = popf(q);

        for (auto next : G[cur]) {
            if (dist[next] != INF) {
                continue;
            }

            q.push_back(next);
            dist[next] = dist[cur] + 1;
        }
    }
}
