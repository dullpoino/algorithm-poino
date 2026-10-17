#pragma once
#include "common.hpp"

void mostfar(VVPLL &G, ll start, PLL &res)
{
    ll N = sz(G);

    VL dist(N, INF);
    dist[start] = 0;
    res = { start, 0 };

    deque<PLL> q;
    q.push_back({ start, 0 });

    while (q.empty() == false) {
        auto &[cur, idx] = q.back();

        if (idx == sz(G[cur])) {
            q.pop_back();
            continue;
        }

        auto [next, cost] = G[cur][idx++];

        if (dist[next] != INF) {
            continue;
        }

        dist[next] = dist[cur] + cost;
        if (dist[next] > snd(res)) {
            res = { next, dist[next] };
        }
        q.push_back({ next, 0 });
    }
}
