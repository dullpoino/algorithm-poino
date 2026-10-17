#pragma once
#include "common.hpp"

bool hasCycle(VVL &G, ll start)
{
    ll N = sz(G);

    VL visited(N, 0);

    deque<PLL> q;

    visited[start] = 1;
    q.push_back({ start, 0 });

    while (q.empty() == false) {
        auto &[cur, idx] = q.back();

        if (idx == sz(G[cur])) {
            visited[cur] = 2;
            q.pop_back();
            continue;
        }

        ll next = G[cur][idx++];

        if (visited[next] == 1) {
            return true;
        }

        if (visited[next] == 2) {
            continue;
        }

        visited[next] = 1;
        q.push_back({ next, 0 });
    }

    return false;
}
