#pragma once
#include "common.hpp"

void bfs01(VVPLL &G, VL &dist, VL &start)
{
    deque<ll> q;
    VL visited(sz(G), 0);
    for (auto s : start) {
        dist[s] = 0;
        q.push_back(s);
    }

    while (q.empty() == false) {
        auto cur = popf(q);

        if (visited[cur] != 0) {
            continue;
        }
        visited[cur] = 1;

        for (auto &[next, val] : G[cur]) {
            if (chmin(dist[next], dist[cur] + val) == false) {
                continue;
            }

            if (val == 0) {
                q.push_front(next);
            }
            else {
                q.push_back(next);
            }
        }
    }
}
