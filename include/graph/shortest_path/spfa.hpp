#pragma once
#include "common.hpp"

bool SPFA(ll N, VVPLL &G, VL &dist, ll start)
{
    VL used(N, 0);
    VL cnt(N, 0);
    deque<ll> q;

    dist[start] = 0;
    q.push_back(start);
    used[start] = 1;

    while (q.empty() == false) {
        auto from = popf(q);
        used[from] = 0;

        for (auto [to, cost] : G[from]) {
            if (chmin(dist[to], dist[from] + cost) == false) {
                continue;
            }

            cnt[to] = cnt[from] + 1;

            if (cnt[to] >= N) {
                return false;
            }

            if (used[to] == 0) {
                q.push_back(to);
                used[to] = 1;
            }
        }
    }

    return true;
}
